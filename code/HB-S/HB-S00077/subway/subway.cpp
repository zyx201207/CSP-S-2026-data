#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define x first
#define y second
inline int read(){
    int d=0,f=0;char ch=getchar();
    while (!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) d=d*10+ch-'0',ch=getchar();
    return f?-d:d;
}
const int N=505,M=500050;
const  ll inf=1e18;

int c,n,m,q,w[M];
vector <pii> e[M];
ll g[N][N];

inline void solve(){
    c=read(),n=read(),m=read(),read(),q=read();
    for (int i=1;i<=m;i++) w[i]=read();
    for (int i=1;i<=n;i++){
        int k=read();
        for (int j=1;j<=k;j++){
            int u=read(),val=read();
            e[u].push_back({i,val});
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i==j) g[i][j]=0;else g[i][j]=inf;
    for (int i=1;i<=m;i++){
        for (int j=0;j<e[i].size();j++){
            int u1=e[i][j].x,w1=e[i][j].y;
            for (int k=j+1;k<e[i].size();k++){
                int u2=e[i][k].x,w2=e[i][k].y;
                g[u1][u2]=g[u2][u1]=min(g[u1][u2],(ll)w1+w2);
            }
        }
    }

    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++) printf("%lld ",g[i][j]);
    //     puts("");
    // }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) g[i][j]=g[j][i]=min(g[i][j],g[i][k]+g[k][j]);
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++) printf("%lld ",g[i][j]);
    //     puts("");
    // }
    while (q--){
        int x=read(),y=read();
        ll ans=inf;
        if (x==y) {puts("0");continue;}
        for (int i=0;i<e[x].size();i++){
            int u=e[x][i].x,w1=e[x][i].y;
            for (int j=0;j<e[y].size();j++){
                int v=e[y][j].x,w2=e[y][j].y;
                ans=min(ans,w1+w2+g[u][v]);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }

}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // auto st=clock();
    solve();
    // cerr<<"cost:"<<1000*(clock()-st)/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}