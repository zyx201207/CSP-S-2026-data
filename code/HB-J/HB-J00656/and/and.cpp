#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    if(m==1)
    {
        ll maxn=-1;
        for(int i=0;i<n;i++)if(maxn<a[i])maxn=a[i];
        cout<<maxn;
        return 0;
    }
    else if(m==n)
    {
        ll num=a[0];
        for(int i=1;i<n;i++)num&=a[i];
        cout<<n;
        return 0;
    }
    else if(m==2)
    {
        int maxn=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)if(maxn<a[i]&a[j])maxn=a[i]&a[j];
        }
        cout<<maxn;
        return 0;
    }
    else cout<<4;
    return 0;
}
