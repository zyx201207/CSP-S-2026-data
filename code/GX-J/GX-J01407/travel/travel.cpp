#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string b1,b2,s1,s2,v1,v2;
    char k1,k2;
    cin>>b1>>s1>>b2>>s2;
    v1=s1.substr(0,1);
    v2=s2.substr(0,1);
    k1=s1[2];
    k2=s2[2];
    if(b1==b2) cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(v1==v2) cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if(k1=='D'||k1=='F')
    {
        if(k2=='D'||k2=='F')
        {
            cout<<"11";
            return 0;
        }
        else
        {
            cout<<"00";
            return 0;
        }
    }
    else
    {
        if(k2=='A'||k2=='B'||k2=='C')
        {
            cout<<1;
            if(k1=='A'&&k2=='B')
            {
                cout<<1;
            }
            else if(k1=='B'&&(k2=='C'||k2=='A'))
            {
                cout<<1;
            }
            else if(k1=='C'&&k2=='B')
            {
                cout<<1;
            }
            else
            {
                cout<<"0";
            }
            return 0;
        }
        else
        {
            cout<<"00";
            return 0;
        }
    }
}
