#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
long long dis[N+500],vis[N+500],n,d,a[N],c,qq,m,k,r,t;
struct node{
    long long v,w;
};

queue<long long>q;
vector<node>g[N+500];
long long dijistal(long long x,long long y){
    memset(dis,0x3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    q.push(x);
    dis[x]=0;
    vis[x]=1;
    while(!q.empty()){
        long long cur=q.front();
        q.pop();
        for(auto e:g[cur]){
            long long v=e.v,w=e.w;
            dis[v]=min(dis[v],dis[cur]+w);
            if(vis[v]==1)continue;
            q.push(v);
            vis[v]=1;
        }
    }
    return dis[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int v;
            cin>>v>>t;
            g[N+i].push_back({v,t});
            g[v].push_back({N+i,t});
        }
    }
    while(qq--){
        long long x,y,ans=0;
        cin>>x>>y;
        cout<<dijistal(x,y)+a[x]+a[y]<<"\n";
    }

    return 0;
}


