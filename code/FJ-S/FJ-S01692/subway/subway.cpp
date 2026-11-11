#include<bits/stdc++.h>
#define int long long
#define R read()
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define gc getchar
using namespace std;
int read()
{
    int x=0,f=1;
    char c=gc();
    while(c<'0'||c>'9') (c=='-'&&(f=-1,1)),c=gc();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=gc();
    return x*f;
}
void write(int x,char xx)
{
    static int st[35],tot=0;
    if(x<0) putchar('-'),x=-x;
    do{st[++tot]=x%10,x/=10;}
    while(x);
    while(tot) putchar(st[tot]+'0'),tot--;
    putchar(xx);
}
#define N 510
#define M 500010
int cid,n,m,d,Q,w[M],f[N][N];
vector<pii>g[M];
int que(int x,int y)
{
    int sum=1e17;
    for(auto i:g[x]) for(auto j:g[y]) sum=min(sum,f[i.fi][j.fi]+i.se+j.se);
    return sum+w[x]+w[y];
}
void solve()
{
    cid=R,n=R,m=R,d=R,Q=R;
    for(int i=1;i<=m;i++) w[i]=R;
    for(int i=1,k,u,v;i<=n;i++)
    {
        k=R;
        while(k--) u=R,v=R,g[u].pb({i,v});
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=1e17;
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++) for(auto j:g[i]) for(auto k:g[i]) f[j.fi][k.fi]=min(f[j.fi][k.fi],j.se+k.se);
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    int u,v;
    while(Q--) u=R,v=R,write(que(u,v),'\n');
}
int T=1;
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // T=R;
    while(T--) solve();
    return 0;
}
/*
NOI2022 1e6 deque?
old OIers,lol
maybe O(md^2+qd^2+n^3)
it's fast,easy to deal with subway6&7
676767676767
maybe it's std.
ez than last year?
15:13 100pts
*/