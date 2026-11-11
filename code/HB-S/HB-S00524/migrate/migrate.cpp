#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+10;
const int N=2e6+10;
int n,d;
int a[N];
int ans;
int sp[N],cnt[N];

void dfs(int u,int st)
{
    for(int i=n;i>=u+1;i--)
    {
        if(a[i]>a[u]+d)continue;
        if(sp[i]==st+1)cnt[i]++;
        sp[i]=min(sp[i],st+1);
        dfs(i,st+1);
    }
}

void solve()
{
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        memset(sp,INF,sizeof(sp));
        memset(cnt,0,sizeof(cnt));
        dfs(i,0);
        for(int j=i+1;j<=n;j++)
            if(cnt[j]==1)ans++;
    }

    cout<<ans<<"\n";
    return;
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}