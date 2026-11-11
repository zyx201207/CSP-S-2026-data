#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[5005],v[5005][5005],top,tt[5005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++)
    {
        top=0;
        for(ll j=i;j<=n;j++)
        {
            bool flag=0;
            ll k=1;
            for(k=1;k<=top;k++)
            {
                if(v[i][k]==a[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                top=k;
            }
            else
            {
                v[i][++top]=a[j];
            }
        }
        cout<<"mj:";
        for(ll j=1;j<=top;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
        tt[i]=top;
    }
    for(ll k=1;k<=m;k++)
    {
        ll cnt=0;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=tt[i];j++)
            {
                if(v[i][j]==k)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<" ";
    }
    return 0;
}
