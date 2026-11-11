#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
ll b[500005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    b[a[n]]=n;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[n])
        b[a[i]]++;
        if(n-i+1==3&&a[i]!=a[n]) b[a[i+1]]++;
    }
    for(int i=1;i<=m;i++)
    {

        cout<<b[i]<<' ';
    }
    return 0;
}
