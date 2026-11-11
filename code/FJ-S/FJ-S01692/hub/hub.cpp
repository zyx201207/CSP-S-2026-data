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
int cid;
#define N 1000010
int n,k,dis[5010][5010],ans,fa[N];
pii e[N];
void solve()
{
    n=R,k=R,ans=1e9;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e9;
    for(int i=1,x,y;i<n;i++) x=R,y=R,dis[x][y]=dis[y][x]=1,e[i]={x,y};
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int o=1;o<=n;o++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][o]+dis[o][j],dis[i][j]);
    for(int S=0;S<(1<<n);S++) if(__builtin_popcountll(S)==k)
    {
        vector<int>v;
        for(int i=1;i<=n;i++) if((S>>(i-1))&1) v.pb(i);
        for(int i=1;i<=n;i++) fa[i]=i;
        int cnt=0;
        for(int i=1;i<n;i++) if((S>>(e[i].fi-1)&1)&&(S>>(e[i].se-1)&1)) cnt++;
        if(cnt<k-2) continue;
        int mus=0;
        for(int i=1;i<=n;i++)
        {
            int sum=1e9;
            for(int j:v) sum=min(sum,dis[i][j]);
            mus=max(mus,sum);
        }
        ans=min(ans,mus);
    }
    write(ans,'\n');
}
int T=1;
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cid=R,T=R;
    while(T--) solve();
    return 0;
}
/*
100+100+48+15=263.
the end.
*/