#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a1,a2;
string b1,b2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a1>>b1>>a2>>b2;
    if(a1!=a2)
    {
        cout<<"0000";
    }
    else
    {
        ll s1,s2;
        s1=s2=0;
        for(ll i=0;i<2;i++)
        {
            s1=s1*10+(b1[i]-'0');
            s2=s2*10+(b2[i]-'0');
        }
        if(s1!=s2)
        {
            cout<<"1000";
        }
        else
        {
            char k1=b1[2],k2=b2[2];
            if('A'<=k1&&k1<='C'&&'A'<=k2&&k2<='C')
            {
                if(k1>k2)
                {
                    swap(k1,k2);
                }
                if(k1=='A'&&k2=='B')
                {
                    cout<<"1111";
                }
                else if(k1=='B'&&k2=='C')
                {
                    cout<<"1111";
                }
                else
                {
                    cout<<"1110";
                }
            }
            else if('D'<=k1&&k1<='F'&&'D'<=k2&&k2<='F')
            {
                cout<<"1111";
            }
            else
            {
                cout<<"1100";
            }
        }
    }
    return 0;
}
