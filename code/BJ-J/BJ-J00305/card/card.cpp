#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll n,m;
ll a[500010];
ll b[500010];
ll tong[500010];
ll sum[500010];
ll r;
ll ans[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        ll l=i;
        while(l<=n)
        {
            ans[a[l]]++;
            l=sum[a[l]]+1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
