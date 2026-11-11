#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5005;
ll n,m,a[N],dis[N][N];
int main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    ll minn=INT_MAX,minpos;
    for(ll i=1;i<=n;i++)
    {
        ll sum=0;
        for(ll j=1;j<=n;j++)
        {
            dis[i][j]=abs(a[i]-a[j]);
            sum+=dis[i][j];
        }
        if(sum<minn)
        {
            minn=sum;
            minpos=i;
        }
    }
    ll arr[N];
    for(ll i=1;i<=n;i++)arr[i]=dis[minpos][i];
    sort(arr+1,arr+1+n);
    ll sum=0,ans=0;
    for(ll i=1;i<=n;i++)
    {
        if(sum+arr[i]<=m)
        {
            sum+=arr[i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
