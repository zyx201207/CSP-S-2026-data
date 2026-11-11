#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fr first 
#define sc second 
#define mk make_pair 
#define pb push_back
const int MAXN=500010,N=1010,inf=1e18;
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;}
int n,m,d,q,a[MAXN],dis[MAXN];
int f[N][N];
vector<pii>G[MAXN],P[MAXN];
vector<pair<pii,int>>Q[MAXN];
int as[MAXN],p[MAXN];
void slv(){
    read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)a[i]=read();
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int i=1;i<=n;i++){
        int k=read();
        while(k--){
            int x=read(),w=read();
            bool fl=0;
            for(auto &o:G[x])if(o.fr!=i)f[o.fr][i]=f[i][o.fr]=min(f[i][o.fr],w+o.sc);
            else o.sc=min(o.sc,w),fl=1;
            if(!fl)G[x].pb(mk(i,w));
            P[i].pb(mk(x,w));
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1;i<=q;i++){as[i]=inf;
        int x=read(),y=read();
        for(auto o:G[x])Q[o.fr].pb(mk(mk(a[x]+a[y]+o.sc,y),i));
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)dis[j]=inf;
        for(int j=1;j<=n;j++){
            for(auto o:P[j])dis[o.fr]=min(dis[o.fr],f[i][j]+o.sc);
        }
        // cout<<i<<":";
        // for(int j=1;j<=m;j++)cout<<dis[j]<<" ";cout<<endl;
        for(auto o:Q[i])as[o.sc]=min(as[o.sc],o.fr.fr+dis[o.fr.sc]);
    }
    for(int i=1;i<=q;i++)printf("%lld\n",as[i]);
}
signed main(){
    freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
    slv();
    return 0;
}