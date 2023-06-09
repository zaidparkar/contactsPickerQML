#ifndef MODELCLASS_H
#define MODELCLASS_H

#include <QAbstractListModel>
#include "ContactClass.cpp"

class ModelClass : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ModelClass(QObject *parent = nullptr);

    enum {
        IDRole,
        NameRole = Qt::UserRole,
        NumberRole
    };


    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    // My methods:
    virtual QHash<int, QByteArray> roleNames() const override;

    void populate(std::list<Contact> data);
    void removeContact(QString contactID);
    void editContact(Contact toEdit);

    QList<Contact> contactList;

public slots:
    void getContacts();
    void deleteContact(QString id);
    void modifyContact(QString id, QString newName, QString newNumber);

private:
};

#endif // MODELCLASS_H
