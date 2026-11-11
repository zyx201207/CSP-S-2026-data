#include<bits/stdc++.h>
#define ll long long
#define F for
#define W while
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?EOF:*p1++)
static inline ll read()
{
    ll x=0,f=1;char ch=gc();
    W(!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}
    W(isdigit(ch)) x=x*10+(ch^48),ch=gc();
    return x*f;
}
const int MAXN=2e6+5;
const ll INF=0x3f3f3f3fLL;
int n;
ll d;
ll a[MAXN];
void solve()
{
    n=read(),d=read();
    int ans=0;
    F(int i=1;i<=n;i++) a[i]=read();
    // cerr<<"-----------\n";
    F(int i=1;i<=n;i++)
    {
        vector<pair<ll,int>> dp(n+1,{INF,0});
        dp[i]={0,1};
        F(int j=i;j<=n;j++)
        {
            if(dp[j].second==2) ans++;
            if(dp[j].second>2) continue;
            F(int k=j+1;k<=n;k++)
            {
                if(a[k]-a[j]>d) break;
                (dp[j].first+1<dp[k].first)?(dp[k].first=dp[j].first+1,dp[k].second=dp[j].second):(dp[j].first+1==dp[k].first?(dp[k].second+=dp[j].second):0);
            }
        }
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=read(),t=read();
    W(t--) solve();
    return 0;
}
/*
*/