#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=501;
int c,n,m,d,r,w[M];
vector<int> q[N];
typedef pair<int,long long> pii;
struct edge{
    int to;
    long long time;
};
vector<pii> tzt[M];//m号站到站台时间
vector<edge> hcsj[N];//换乘时间
priority_queue<pii,vector<pii>,greater<pii>> p;
int dijkstra(int s,int f){
    while(!p.empty()){
        p.pop();
    }
    bool vis[N];
    int dis[N];
    memset(vis,false,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    p.push({0,s});
    while(!p.empty()){
        pii x=p.top();
        p.pop();
        int mi=x.second;
        //cout<<mi<<endl;
        if(vis[mi]){
            continue;
        }
        hcsj[s].push_back({mi,x.first});
        dis[mi]=x.first;
        vis[mi]=true;
        for(auto e:hcsj[mi]){
            if(dis[e.to]>dis[mi]+e.time){
                hcsj[s].push_back({e.to,dis[mi]+e.time});
                //cout<<s<<" "<<e.to<<" "<<dis[mi]+e.time<<endl;
                p.push({dis[mi]+e.time,e.to});
            }
        }
    }
    return 0;
}
int main(){
    freopen("subway.in","r",stdin);                                              
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>r;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            q[i].push_back(a);
            tzt[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto j:tzt[i]){
            for(auto e:tzt[i]){
                if(e.first==j.first){
                    hcsj[j.first].push_back({j.first,0});
                }
                if(e.first<j.first){
                    hcsj[e.first].push_back({j.first,e.second+j.second});
                    hcsj[j.first].push_back({e.first,e.second+j.second});
                }
            }
        }
    }
    bool di[N];
    memset(di,false,sizeof(di));
    for(int i=1;i<=r;i++){
        int x,y;
        cin>>x>>y;
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(auto j:tzt[x]){
            for(auto e:tzt[y]){
                //if(!di[j.first]){
                    if(j.first==1) dijkstra(j.first,e.first);//shanchupanduan
                    //di[j.first]=true;
                //}
                for(auto o:hcsj[j.first]){
                    if(o.to==e.first){
                        //cout<<j.first<<" "<<e.first<<" "<<o.time<<endl;
                        ans=min(ans,(long long)w[x]+w[y]+j.second+e.second+o.time);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}