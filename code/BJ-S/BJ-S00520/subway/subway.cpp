#include <bits/stdc++.h>
using namespace std;
struct edge{
    long long u,v,w;
};
long long c,n,m,d,q;
long long w[500005];
struct ways{
    long long v = 0,w = 0;
};
vector <ways> md[500005];
long long f[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i = 1; i <= m; i++){
        cin>>w[i];
    }
    for(long long i = 1; i <= n; i++){
        long long ki;
        cin>>ki;
        for(long long j = 1; j <= ki; j++){
            long long aij, tij;
            cin>>aij>>tij;
            md[aij].push_back((ways){i,tij});
        }
    }
    memset(f,0x3f,sizeof(f));
    for(long long i = 1; i <= m; i++){
        for(long long u = 0; u <= md[i].size(); u++){
            for(long long v = 0; v <= md[i].size(); v++){
                if(md[i][u].w && md[i][v].w){
                    f[md[i][u].v][md[i][v].v] = min(f[md[i][u].v][md[i][v].v],md[i][u].w+md[i][v].w);
                    f[md[i][v].v][md[i][u].v] = min(f[md[i][v].v][md[i][u].v],md[i][u].w+md[i][v].w);
                    //cout<<f[md]
                }
            }
        }
    }
    for(long long i = 1; i <= n; i++){
        f[i][i] = 0;
    }
    for(long long k = 1; k <= n; k++){
        for(long long i = 1; i <= n; i++){
            for(long long j = 1; j <= n; j++){
                if(f[i][k] == 0x3f3f3f3f3f3f3f3fll){
                    //continue;
                }
                f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
            }
        }
    }
    for(long long i = 1; i <= q; i++){
        long long st,ed;
        cin>>st>>ed;
        long long ans = 0x3f3f3f3f3f3f3f3fll;
        for(long long ui = 0; ui < md[st].size(); ui++){
            for(long long vi = 0; vi < md[ed].size(); vi++){
                long long u = md[st][ui].v, v = md[ed][vi].v;
                long long uw = md[st][ui].w, vw = md[ed][vi].w;
                if(uw + vw + f[u][v] < ans){
                    ans = uw + vw + f[u][v];
                }
            }
        }
        cout<<ans + w[st] + w[ed]<<endl;
    }
}
