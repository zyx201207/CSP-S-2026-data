#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
int f[N];
int ans;
int n,m;
void dfs(int step,int sum,int cnt)
{
    if(cnt>m) return;
    if(step==n+1)
    {
        if(cnt==m) ans=max(ans,sum);
        return;
    }
    if(cnt==0) sum=a[step];
    dfs(step+1,sum&a[step],cnt+1);
    dfs(step+1,sum,cnt);
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int maxn=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(a[i],maxn);
    }
    int x=a[1];
    for(int i=2;i<=n;i++) x=x&a[i];
    if(m==1)
    {
        cout<<maxn;
        return 0;
    }
    if(m==n)
    {
        cout<<x;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
