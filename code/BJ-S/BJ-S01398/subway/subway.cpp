#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll w[20005];
struct node{
    ll num,to,id,ext,fnum;
};
ll c,n,m,d,q;
vector<node>v[20005][550];
vector<ll>vec[550];
ll dis[2005][2005];
bool vis[20005];
ll cost[20005][550];
void init(){
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            dis[i][j]=9e18;
        }
    }
}
void init2(){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<v[i][j].size();k++){
                v[i][j][k].fnum=v[i][j][k].num;
                v[i][j][k].ext=0ll;
            }
        }
    }
}
void bfs(ll start){
    queue<node>q;
    vis[start]=true;
    for(ll j=1;j<=n;j++){
        for(ll i=0;i<v[start][j].size();i++){
            q.push(v[start][j][i]);
        }
    }
    while(!q.empty()){
        node r=q.front();
        q.pop();
        if(vis[r.to])continue;
        vis[r.to]=true;
        //if(r.to==6)cout<<w[start]<<" "<<cost[start][r.fnum]<<" "<<cost[r.to][r.num]<<" "<<w[r.to]<<" "<<r.ext<<'\n';
        dis[start][r.to]=min(dis[start][r.to],w[start]+cost[start][r.fnum]+cost[r.to][r.num]+w[r.to]+r.ext);
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<v[r.to][i].size();j++){
                node k=v[r.to][i][j];
                if(k.to==r.id)continue;
                if(k.num!=r.num){
                    //cout<<k.num<<' '<<k.id<<' '<<k.to<<' '<<r.num<<' '<<r.id<<' '<<r.to<<'\n';
                    k.ext+=cost[r.to][r.num];
                    k.ext+=cost[r.to][k.num];
                }else{
                    k.ext=r.ext;
                }
                k.fnum=r.fnum;
                q.push(k);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    init();
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x;
        for(ll j=1;j<=x;j++){
            ll a,b;
            cin>>a>>b;
            vec[i].push_back(a);
            cost[a][i]=b;
        }
        for(ll j=1;j<vec[i].size();j++){
            v[vec[i][j]][i].push_back({i,vec[i][j-1],vec[i][j],0ll,i});
            v[vec[i][j-1]][i].push_back({i,vec[i][j],vec[i][j-1],0ll,i});
        }
    }
    for(ll i=1;i<=m;i++){
        init2();
        bfs(i);
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        cout<<dis[x][y]<<'\n';
    }
    return 0;
}