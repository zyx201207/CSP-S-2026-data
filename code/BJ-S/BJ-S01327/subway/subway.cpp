#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
inline int read(){
    int f=0,x=1;
    char c=getchar();
    while (c<'0'||c>'9'){
        if (c=='-') x=-1;
        c=getchar();
    }
    while (c>='0'&&c<='9'){
        f=f*10+c-48;
        c=getchar();
    }
    return f*x;
}
int c,m,n,d,q;
int W[N];
struct node{
    int v,w;
};
vector<node> g[N+500];
int f[505][505];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //cin>>c>>m>>n>>d>>q;
    c=read();
    m=read();
    n=read();
    d=read();
    q=read();
    for (int i=1;i<=n;i++) W[i]=read();
    for (int i=1;i<=m;i++){
        int k=read();
        //cin>>k;
        for (int j=1;j<=k;j++){
            int u=read(),w=read();
            //cin>>u>>w;
            g[u].push_back({i+n,w});
        }
    }
    memset(f,0x3f,sizeof f);
    for (int i=1;i<=m;i++){
        f[i][i]=0;
    }
    for (int u=1;u<=n;u++){
        for (int i=0;i<g[u].size();i++){
            for (int j=i+1;j<g[u].size();j++){
                int U=g[u][i].v-n;
                int V=g[u][j].v-n;
                f[U][V]=f[V][U]=min(f[U][V],g[u][i].w+g[u][j].w);
            }
        }
    }
    /*
    for (int i=1;i<=m;i++){
        for (int j=1;j<=m;j++){
            cout<<f[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    for (int k=1;k<=m;k++){
        for (int i=1;i<=m;i++){
            for (int j=1;j<=m;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while (q--){
        int u=read(),v=read();
        //cin>>u>>v;
        int ans=9e18;
        for (int i=0;i<g[u].size();i++){
            for (int j=0;j<g[v].size();j++){
                int U=g[u][i].v-n;
                int V=g[v][j].v-n;
                ans=min(ans,g[u][i].w+g[v][j].w+f[U][V]);
            }
        }
        cout<<ans+W[u]+W[v]<<'\n';
    }
    return 0;
}
