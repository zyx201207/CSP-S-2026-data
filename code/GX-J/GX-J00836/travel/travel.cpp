#include <bits/stdc++.h>
using namespace std;
string l="0ABC0";
string r="0DF0";
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;

    int rp=stoi(s1.substr(0,2));
    int xp=stoi(s2.substr(0,2));

    char rc=s1[2];
    char xc=s2[2];

    if(c1==c2)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }

    if(rp==xp)
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }

    char c='N';
    if(l.find(rc)!=-1&&l.find(xc)!=-1)
    {
        cout<<"1";
        c='L';
    }
    else if(r.find(rc)!=-1&&r.find(xc)!=-1)
    {
        cout<<"1";
        c='R';
    }
    else
    {
        cout<<"00";
        return 0;
    }
    int p;
    if(c=='L')
    {
        p=l.find(rc);
        if(l[p+1]==xc||l[p-1]==xc)
        {
            cout<<"1";
        }else cout<<"0";
    }
    else
    {
        p=r.find(rc);
        if(r[p+1]==xc||r[p-1]==xc)
        {
            cout<<"1";
        }else cout<<"0";
    }
    return 0;
}
