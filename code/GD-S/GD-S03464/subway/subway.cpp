#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10;
int opyl,n,m,d,q;
int k[M],v[M];
int dis[M]; 
int dis2[2001][2001];
int vis[5001][5001];
int cnt;
vector<pair<int,int>> E[M];
struct node{
    int x,dis;
    friend bool operator<(node x,node y){
        return x.dis>y.dis;
    }
};
int dij(int nk,int to){
    priority_queue<node> q;
    memset(dis,0x3f,sizeof dis);
    q.push({nk,0});
    dis[nk]=0;
    while(!q.empty()) {
        auto Vx=q.top();
        q.pop();
        int vx=Vx.x,wx=Vx.dis;
        if(vx==to) return wx;
        for(auto V:E[vx]){
            if(dis[V.first]>dis[vx]+V.second) {
                dis[V.first]=dis[vx]+V.second;
                q.push({V.first,dis[V.first]});
            }
        }
    }
    return -1;
}
void dij2(int nk){
    priority_queue<node> q;
    q.push({nk,0});
    dis2[nk][nk]=0;
    while(!q.empty()) {
        auto Vx=q.top();
        q.pop();
        int vx=Vx.x,wx=Vx.dis;
        for(auto V:E[vx]){
            // if(V.first<nk) {
            //     for(int i=1;i<=n;i++) dis2[nk][i]=min(dis2[nk][i],dis2[V.first][i]+V.second+dis2[nk][vx]);
            //     continue;
            // }
            // else 
            if(dis2[nk][V.first]>dis2[nk][vx]+V.second) {
                dis2[nk][V.first]=dis2[nk][vx]+V.second;
                q.push({V.first,dis2[nk][V.first]});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>opyl>>m>>n>>d>>q;
    for(int i=1;i<=n;i++) cin>>v[i];
    cnt=n;
    // for(int i=1;i<=n;i++)
    for(int i=1;i<=m;i++) {
        cin>>k[i];
        ++cnt;
        for(int j=1;j<=k[i];j++) {
            int aa,ww;
            cin>>aa>>ww;
            E[aa].push_back({cnt,ww});
            E[cnt].push_back({aa,ww});
        }
    }
    if(opyl<=11 && opyl>=9) {
        // cout<<"FUCK";
        memset(dis2,0x3f,sizeof dis2);
        for(int i=1;i<=n;i++) dij2(i);
        while(q--) {
            int u,v2;
            cin>>u>>v2;
            if(u==v2){
                cout<<"0\n";
                continue;
            }
            if(vis[u][v2]) cout<<vis[u][v2]<<"\n";
            else{   
                int tmp=dis2[u][v2];
                vis[u][v2]=v[u]+v[v2]+tmp;
                cout<<vis[u][v2]<<"\n";
            }
        }
        return 0;
    }
    while(q--) {
        int u,v2;
        cin>>u>>v2;
        if(u<=5000 && v2<=5000) {
            if(vis[u][v2]) cout<<vis[u][v2]<<"\n";
            else{   
                int tmp=dij(u,v2);
                vis[u][v2]=v[u]+v[v2]+tmp;
                cout<<vis[u][v2]<<"\n";
            }
        }
        else{
            int tmp=dij(u,v2);
            cout<<v[u]+v[v2]+tmp<<"\n";
        }
    }
}