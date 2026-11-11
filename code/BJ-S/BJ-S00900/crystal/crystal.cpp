#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],ans=0,d[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            d[j]=a[i]-a[j];
        }
        sort(d+1,d+i+1);
        int sum=0,now=0;
        while(sum<=m&&now<=i)
        {
            now++;
            sum+=d[now];
        }
        ans=max(ans,now-1);
    }
    cout<<ans;
    return 0;
}
