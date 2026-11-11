#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int o[500500];
long long dis[505][500500];
vector<pair<int,long long> > v[500505];
void dfs(int nod,long long d,int fa,int r){
    if(nod<=m){
        if(dis[r][nod]){
            if(d<dis[r][nod]){
                dis[r][nod]=d;
            }else{
                return;
            }
        }else{
            dis[r][nod]=d;
        }
    }
    for(auto s:v[nod]){
        if(s.first!=fa) dfs(s.first,d+s.second,nod,r);
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>o[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            v[a].push_back({m+i,t});
            v[m+i].push_back({a,t});
        }
    }
    for(int i=m+1;i<=m+n;i++){
        dfs(i,0,0,i-m);
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long minn=1e18;
        for(int i=1;i<=n;i++){
            minn=min(minn,dis[i][x]+dis[i][y]);
        }
        cout<<minn+o[x]+o[y]<<'\n';
    }
    return 0;
}
