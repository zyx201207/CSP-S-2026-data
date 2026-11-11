#include<iostream>
#include<algorithm>
#define N 500005
#define int long long
using namespace std;
int n,m;
int a[N];
int ans,nans,sum;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum+=(a[i]-a[i-1])*nans;
        while(sum>m)
            sum-=a[i]-a[i-nans],nans--;
        nans++;
        ans=max(nans,ans);
    }
    cout<<ans;
    return 0;
}