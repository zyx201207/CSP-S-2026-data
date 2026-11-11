#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int p[15],C,t,n,a[N],d,b[N],cnt,tr[N],ans;
int f[15][15],g[15][15];
inline void dfs(int step)
{
    if(step>n)
    {
        vector<int> tmp(15,0);
        int cnt=0;
        for(int i=1;i<=n;i++) if(p[i]) tmp[++cnt]=i;
        for(int i=1;i<cnt;i++)
        {
            if(a[tmp[i+1]]-a[tmp[i]]>d) return;
        }
        for(int i=2;i<cnt;i++) 
        {
            if(a[tmp[i+1]]-a[tmp[i-1]]<=d) return;
        }
        if(cnt<=2) return;
        if(g[tmp[1]][tmp[cnt]]==cnt) f[tmp[1]][tmp[cnt]]++;
        if(g[tmp[1]][tmp[cnt]]==0||g[tmp[1]][tmp[cnt]]>cnt) 
        {
            f[tmp[1]][tmp[cnt]]=1;
            g[tmp[1]][tmp[cnt]]=cnt;
        }
        return;
    }
    p[step]=0;
    dfs(step+1);
    p[step]=1;
    dfs(step+1);
}
inline void solve()
{
    dfs(1);
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=n;j++) 
        {
            if(f[i][j]==2) ans++;
        }
    }
    cout<<ans<<'\n';
}
int dp[305],cnts[305];
inline void solve1()
{
    int ans=0;
    for(int i=1;i<n;i++) 
    {
        memset(dp,0,sizeof(dp));
        memset(cnts,0,sizeof(cnts));
        cnts[i]=1;
        for(int j=i+1;j<=n;j++)
        {
            
            int pmin=LONG_LONG_MAX,sum=0;
            for(int k=j-1;k>=i;k--) 
            {
                if(a[j]-a[k]>d) break;
                if(dp[k]<pmin) { pmin=dp[k];sum=0;}
                if(dp[k]==pmin) sum+=cnts[k];
            }
            cnts[j]=sum;
            dp[j]=pmin+1;
            if(cnts[j]==2) ans++;
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n<=9) solve();
        else solve1(); 
    }
    return 0;
}
