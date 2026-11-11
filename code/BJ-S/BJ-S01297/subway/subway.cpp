#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int w,id;
    friend bool operator<(node a,node b){
        return a.w>b.w;
    }
};
int C,n,m,d,q;
int w[50009];
int vis[50009];
vector<pair<int,int>> a[50009];
int dd[50009];
int dijkstra(int x,int y){
    memset(vis,0,sizeof(vis));
    priority_queue<node> q;
    q.push({0,x});
    for(int i=1;i<=50000;++i)dd[i]=1e18;
    dd[x]=0;
    while(q.size()){
        int x=q.top().id;
        q.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(auto i:a[x]){
            if(i.second+dd[x]<dd[i.first]){
                dd[i.first]=i.second+dd[x];
                q.push({dd[i.first],i.first});
            }
        }
    }
    return dd[y];
}
map<pair<int,int>,int> dz;
void dijkstra2(int s){
    memset(vis,0,sizeof(vis));
    priority_queue<node> q;
    q.push({0,s});
    dz[{s,s}]=0;
    while(q.size()){
        int x=q.top().id;
        q.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(auto i:a[x]){
            if(dz.count({s,i.first})==0||i.second+dz[{s,x}]<dz[{s,i.first}]){
                dz[{s,i.first}]=i.second+dz[{s,x}];
                q.push({dz[{s,i.first}],i.first});
            }
        }
    }
}
vector<int> b[50009];
int mo[23009];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    if(C>=1&&C<=8){
        for(int i=1;i<=n;++i){
            int k;
            cin>>k;
            for(int j=1;j<=k;++j){
                int A,t;
                cin>>A>>t;
                int k6=1e4;
                a[A].push_back({i+k6,t});
                a[i+k6].push_back({A,t});
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<dijkstra(x,y)+w[x]+w[y]<<'\n';
        }
        return 0;
    }
    if(C>=9&&C<=11){
        for(int i=1;i<=n;++i){
            int k;
            cin>>k;
            for(int j=1;j<=k;++j){
                int A,t;
                cin>>A>>t;
                int k6=1e4;
                a[A].push_back({i+k6,t});
                a[i+k6].push_back({A,t});
            }
        }
        for(int i=1;i<=m;++i){
            dijkstra2(i);
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<dz[{x,y}]+w[x]+w[y]<<'\n';
        }
        return 0;
    }
    if(C>=12&&C<=15){
        int gg;
        for(int i=1;i<=n;++i){
            int k;
            cin>>k;
            for(int j=1;j<=k;++j){
                int k6=2e4;
                int A,t;
                cin>>A>>t;
                gg=t;
                b[A].push_back(i+k6);
                b[i+k6].push_back(A);
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            memset(mo,-1,sizeof(mo));
            queue<int> qq;
            qq.push(x);
            mo[x]=0;
            while(!qq.empty()){
                int x=qq.front();
                qq.pop();
                for(auto i:b[x]){
                    if(mo[i]==-1){
                        mo[i]=mo[x]+1;
                        qq.push(i);
                        if(i==y)break;
                    }
                }
            }
            cout<<mo[y]*gg+w[x]+w[y]<<'\n';
        }
        
    }
    return 0;
}