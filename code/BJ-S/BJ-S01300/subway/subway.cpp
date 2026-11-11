#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1,M=5e2+1;
int c,n,m,d,q,w[N],ans=0;
void fio(const string&str){
#ifndef COMPL
    freopen((str+".in").c_str(),"r",stdin);
    freopen((str+".out").c_str(),"w",stdout);
#endif
}
int dis[M][M];
vector<pair<int,int>>vec[N];
void chkm(int&x,int y){
    x=min(x,y);
}
signed main(){
    fio("subway");
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int a,t;
            cin>>a>>t;
            vec[a].emplace_back(i,t);
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(auto u:vec[i]){
            for(auto v:vec[i]){
                chkm(dis[u.first][v.first],u.second+v.second);
                chkm(dis[v.first][u.first],u.second+v.second);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                chkm(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        int ans=0x3f3f3f3f3f3f3f3f;
        for(auto s:vec[u]){
            for(auto t:vec[v]){
                chkm(ans,s.second+t.second+dis[s.first][t.first]);
            }
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}