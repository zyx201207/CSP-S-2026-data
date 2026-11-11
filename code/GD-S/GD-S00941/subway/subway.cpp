#include<bits/stdc++.h>
#define M 505
#define N 20005
using namespace std;
int c,n,m,d,q;
int w[N];
vector<int> p[N];
int t[N][M];
vector<int> sta[M];
vector<pair<int,int>> g[N][M];
int dis[N][M];
int ans[M];
int st,ed;
struct node{
    int v,st,l;
};

void dij(){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
    memset(dis,0x3f,sizeof(dis));
    for(auto i:p[st]){
        dis[st][i]=t[st][i];
        q.push({dis[st][i],{st,i}});
    }   
    while(q.size()){
        auto tt=q.top();
        q.pop();
        int w=tt.first;
        int u=tt.second.first;
        int l=tt.second.second;
        if(w!=dis[u][l])continue;
        bool f=0;
        for(auto v:sta[l]){
            if(!f&&v!=u)continue;
            if(v==u){
                f=1;
                int t1=t[u][l];
                for(auto l1:p[u]){
                    if(l1==l)continue;
                    int t2=t[u][l1];
                    if(dis[u][l]+t1+t2<=dis[u][l1]){
                        dis[u][l1]=dis[u][l]+t1+t2;
                        q.push({dis[u][l1],{u,l1}});
                    }
                }
            }
            if(f){
                int t1=t[u][l];
                int t2=t[v][l];
                if(dis[u][l]<dis[v][l]){
                    dis[v][l]=dis[u][l];
                    q.push({dis[v][l],{v,l}});
                }
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=m;i++){
        cin>>ans[i];
        for(int j=1;j<=ans[i];j++){
            int u,ti;
            cin>>u>>ti;
            p[u].push_back(i);
            t[u][i]=ti;
            sta[i].push_back(u);
            for(auto l:p[u]){
                if(l==i)continue;
                g[u][i].push_back({l,t[u][l]+ti});
                g[u][l].push_back({i,ti+t[u][l]});
            }
        }
    }
    
    while(q--){
        cin>>st>>ed;
        dij();
        int ans=INT_MAX;
        int l1=0;
        for(auto l:p[ed]){
            ans=min(ans,dis[ed][l]);
            if(ans==dis[ed][l])l1=l;
        }
        cout<<ans+w[st]+w[ed]+t[ed][l1]<<"\n";
    }
    return 0;
}
