#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    int a1,a2;
    a1=(s1[0]-'0')*10+s1[1]-'0';
    a2=(s2[0]-'0')*10+s2[1]-'0';
    if(a1!=a2)
    {
        cout<<"000";
        return 0;
    }
    cout<<1;
    char b1=s1[2],b2=s2[2];
    if(b1>='A'&&b1<='C')
    {
        if(b2>='A'&&b2<='C')
        {
            cout<<1;
            if(abs(b1-b2)==1)
            {
                cout<<1;
                return 0;
            }
            else
            {
                cout<<0;
                return 0;
            }
        }
        else
        {
            cout<<"00";
            return 0;
        }
    }
    else if(b1=='D'||b1=='F')
    {
        if(b2=='D'||b2=='F')
        {
            cout<<11;
            return 0;
        }
        else
        {
            cout<<"00";
            return 0;
        }
    }

    return 0;
}

