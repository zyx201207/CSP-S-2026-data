#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define per(i,a,b) for(int i=(a);i>=(int)(b);i--)
#define all(v) v.begin(),v.end()
#define lb(x) ((x) & -(x))
#define clz(x) __builtin_clz(x)
#define lg(x) (clz(1)-clz(x))
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back
#define siz(x) ((int)x.size())
using namespace std;
const int N=5e6+10;
int n,D,a[N],nx[N],R[N],ans;
vector<int> G[N];
int cnt0[N],cnt1[N],dlt[N];
int res[N];
void dfs(int x)
{
    if(nx[x]!=n+1&&nx[nx[x]]!=n+1)
    {
        int y=nx[x],ny=nx[y];
        cnt0[x]=cnt0[y]+y-x,cnt1[x]=cnt1[y];
        if(nx[y-1]<=ny-2)
        {
            int tl=y+1,tr=nx[y-1];
            if(x<y-2) tl=nx[y-2]+1;
            int cur=tr-tl+1;
            dlt[x]=cur,cnt1[x]+=cur,cnt0[x]-=nx[y-1]-y;
        }
        else if(nx[y-1]==ny-1)
        {
            int tl=y+1,tr=nx[y-1];
            if(x<y-2&&nx[y-2]<ny-1)
            {
                tl=nx[y-2]+1;
                int cur=tr-tl+1;
                dlt[x]=cur;
                cnt1[x]+=cur-dlt[y],cnt0[x]-=nx[y-1]-y;
            }
            else if(x==y-2)
            {
                int cur=tr-tl+1;
                dlt[x]=cur;
                cnt1[x]+=cur-dlt[y],cnt0[x]-=nx[y-1]-y;
            }
            else cnt1[x]-=dlt[y],cnt0[x]-=nx[y-1]-y;
        }
        else
        {
            cnt0[x]-=cnt0[y];
            if(x==y-2) dlt[x]=cnt1[x]=cnt0[y];
            else if(nx[y-2]<=ny-2) dlt[x]=cnt1[x]=cnt0[y]-(nx[y-2]-y);
            else if(nx[y-2]==ny-1) dlt[x]=cnt1[x]=cnt0[y]-(nx[y-2]-y);
            else dlt[x]=cnt1[x]=0;
        }
       // cout<<x<<" "<<cnt0[x]<<" "<<cnt1[x]<<"\n";
        ans+=cnt1[x];
    }
    for(auto y:G[x]) dfs(y);
}
void solve()
{
    ans=0;
    cin>>n>>D;
    rep(i,1,n+1) G[i].clear(),cnt0[i]=cnt1[i]=0,dlt[i]=0,nx[i]=n+1,R[i]=n+1;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n)
    {
        int p=upper_bound(a+1,a+n+1,a[i]+D)-a-1;
        if(p==i) nx[i]=n+1;
        else nx[i]=p;
        G[nx[i]].pb(i);
    }
    R[n]=n;
    per(i,n-1,1)
        if(a[i+1]-a[i]<=D) R[i]=R[i+1];
        else R[i]=i;
    rep(i,1,n) cnt0[i]=R[i]-i;
    dfs(n+1);
    cout<<ans<<"\n";
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int c,T; cin>>c>>T;
    while(T--) solve();
    return 0;
}
