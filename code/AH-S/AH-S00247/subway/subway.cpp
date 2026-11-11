#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
long long t,a,b,c,dis[500005],q,d[500005];
bool vis[500005];
struct node{
    int v,w;
    bool operator < (const node &x) const{
        return w<x.w;
    }
};
vector<node> g[500005];
long long gu(long long st,long long ed){
    queue<int> p;
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    p.push(st);
    vis[st]=1;
    dis[st]=0;
    while(!p.empty()){
        int u=p.front();
        p.pop();
        vis[u]=0;
        for(int n=0;n<g[u].size();n++){
            node x=g[u][n];
            int v=x.v;
            if(dis[v]>dis[u]+x.w){
                dis[v]=dis[u]+x.w;
                if(!vis[v]){
                    p.push(v);
                    vis[v]=1;
                }

            }
        }
    }
    return dis[ed];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>q>>a>>b>>c>>t;
    for(int n=1;n<=b;n++){
        cin>>d[n];
    }
    for(int n=1,x;n<=a;n++){
        cin>>x;
        int t[500005],u[500005];
        for(int m=1;m<=x;m++){
            cin>>t[m]>>u[m];
        }
        for(int i=1;i<=x;i++){
            for(int j=i+1;j<=x;j++){
                g[t[i]].push_back({t[j],u[i]+u[j]});
                g[t[j]].push_back({t[i],u[i]+u[j]});
            }
        }
    }
    while(t--){
        int st,ed;
        cin>>st>>ed;
        cout<<gu(st,ed)<<endl;
    }
    return 0;
}
