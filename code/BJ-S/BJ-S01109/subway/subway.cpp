#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int inf=0x3f3f3f3f;
vector<pair<int,int>>e[N];
struct node{
    int id,len;
    bool operator<(node a)const{
        a.len<len;
    }
};
int c,n,m,d,q;
int dis[N];
bool vis[N];
int w[N];
void dij(int s){
    fill(dis,dis+N,inf);
    fill(vis,vis+N,0);
    priority_queue<node>q;
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()){
        int x=q.top().id;
        int len=q.top().len;
        q.pop();
        if(vis[x]){
            continue;
        }
        vis[x]=1;
        for(auto it:e[x]){
            int y=it.first;
            int z=it.second;
            if(dis[x]+z<dis[y]){
                dis[y]=dis[x]+z;
                q.push({y,dis[y]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int a[k+10]={},t[k+10]={};
        for(int j=1;j<=k;j++){
            cin>>a[j];
            cin>>t[j];
        }
        if(k<=2){
            if(k==2){
                e[a[1]].push_back({a[2],t[1]+t[2]});
                e[a[2]].push_back({a[1],t[1]+t[2]});
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        dij(x);
        cout<<dis[y]+w[x]+w[y]<<endl;
    }
    return 0;
}
