
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,D=25;
int c,n,m,d,q;
int w[N];
int a[M],t[M];
struct edge{
    int v,w;
    edge(int a,int b){v=a,w=b;}
    bool operator>(const edge &a)const{return w>a.w;}
};
vector<edge> g[D*N];
void add(int u,int v,int w){
    g[u].push_back(edge(v,w));
}
int dis[D*N],vis[D*N];
int dij(int a,int b){
    priority_queue<edge,vector<edge>,greater<edge> > q;
    q.push(edge(a,0));
    dis[a]=0,vis[a]=1;
    //cout << "$";
    while(!q.empty()){
        int u=q.top().v;
        q.pop();
   // cout << g[u].size() << " ";
        for(auto x:g[u]){
            int v=x.v,w=x.w;
   // cout << "#";
            //cout << dis[u] << " ";
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                //cout << dis[v] <<" ";
                if(!vis[v]){
                    vis[v]=1;
                    q.push(edge(v,dis[v]));
                }
            }
        }
    }
    return dis[b];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        for(int j = 0;j < x;j++){
            cin >> a[j] >> t[j];
        }
        const int K=m*i;
        for(int j = 0;j < x;j++){
            if(j){
                add(a[j]+K,a[j-1]+K,0);
                add(a[j-1]+K,a[j]+K,0);
            }
            add(a[j],a[j]+K,t[j]);
            add(a[j]+K,a[j],t[j]);
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        memset(dis,0x3f,sizeof dis);
        memset(vis,0x00,sizeof vis);
        cout << w[x]+dij(x,y)+w[y] << endl;
    }
}
