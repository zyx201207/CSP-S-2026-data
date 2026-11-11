#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<long long,long long>
const int N=505,M=5e5+5,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[M];
vector<pii>vec[M];
int f[N][N];
int solve(int u,int v){
    int res=INF;
    int j=0;
    for(int i=0;i<vec[u].size();i++){
        int lineu=vec[u][i].first,w1=vec[u][i].second;
        for(int j=0;j<vec[v].size();j++){
            int linev=vec[v][j].first,w2=vec[v][j].second;
            // if(linej!=lineu)continue;
            // cerr<<"lineu=="<<lineu<<" linev=="<<linev<<" f[u][v]=="<<f[lineu][linev]<<" w1=="<<w1<<" w2=="<<w2<<'\n';
            res=min(res,f[lineu][linev]+w1+w2);
        }
    }
    // cerr<<"u=="<<u<<" v=="<<v<<" res=="<<res<<'\n';
    return res+w[u]+w[v];
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            vec[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)f[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        int u=vec[i][0].first,w1=vec[i][0].second;
        // cerr<<"i=="<<i<<" v=="<<u<<" w=="<<w1<<' ';
        for(int j=1;j<vec[i].size();j++){
            int v=vec[i][j].first,w2=vec[i][j].second;
            // cerr<<"v=="<<v<<" w=="<<w2<<' ';
            f[u][v]=min(f[u][v],w1+w2);
            f[v][u]=f[u][v];
            // cerr<<"i=="<<i<<" u=="<<u<<" v=="<<v<<" f[u][v]=="<<f[u][v]<<'\n';
        }
        // cerr<<'\n';
        // sort(vec[i].begin(),vec[i].end());
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cerr<<f[i][j]<<' ';
    //     }
    //     cerr<<'\n';
    // }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j||f[i][k]==INF||f[k][j]==INF)continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cerr<<f[i][j]<<' ';
    //     }
    //     cerr<<'\n';
    // }
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<solve(u,v)<<'\n';
    }
    return 0;
}