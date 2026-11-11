#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;

namespace shizuru_nakatsu{
    int n,m,d,q;
    int W[500005];
    ll dis[505][505];
    vector<pair<int,int> >stat[500005];
    void init(){
        memset(dis,0x3f,sizeof(dis));
        int c;
        cin>>c>>n>>m>>d>>q;
        for(int i=1;i<=m;i++){
            cin>>W[i];
        }
        for(int i=1;i<=n;i++){
            dis[i][i]=0;int k;cin>>k;
            for(int j=1;j<=k;j++){
               pair<int,int>pr;cin>>pr.first>>pr.second;
               stat[pr.first].push_back({i,pr.second});
            }
        }
        for(int i=1;i<=m;i++){
            for(auto u:stat[i]){
                for(auto v:stat[i]){
                    if(u==v)continue;
                    dis[u.first][v.first]=min(dis[u.first][v.first],(ll)u.second+v.second);
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
    }
    void my_love(){
        while(q--){
            int u,v;cin>>u>>v;
            ll res=1e18,ces=0;
            ces=W[u]+W[v];
            for(auto i:stat[u]){
                for(auto j:stat[v]){
                    res=min(res,dis[i.first][j.first]+i.second+j.second+ces);
                }
            }
            cout<<res<<"\n";
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        shizuru_nakatsu::init();
        shizuru_nakatsu::my_love();
    }
    return 0;
}