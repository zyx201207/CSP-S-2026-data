#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct edge{
    int w;
    int to;
    bool operator <(const edge&x)const
    {
        return x.w<w;
    }
};
int c,n,m,d,q;
vector<edge>e[1000010];
int t[500005];
int dis[500005];
bool vis[500005];
void dijk(int x,int y){
    priority_queue<edge>q;
    q.push({0,x});
    while(!q.empty()){
        edge tmp=q.top();
        q.pop();
        if(vis[tmp.to]) continue;
        vis[tmp.to]=1;
        dis[tmp.to]=tmp.w;
        for(auto i:e[tmp.to]){
            q.push({tmp.w+i.w,i.to});
        }
    }
    cout<<dis[y]<<endl;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        int tmp;
        cin>>tmp;
        e[i].push_back({tmp,i+m});
        e[i+m].push_back({tmp,i});
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int a[500005]={};
        for(int j=1;j<=k;j++){
            cin>>a[j];
            cin>>t[a[j]];
            for(int tmp=1;tmp<j;tmp++){
                e[a[tmp]].push_back({t[a[tmp]]+t[a[j]],a[j]});
                e[a[j]].push_back({t[a[tmp]]+t[a[j]],a[tmp]});
            }
        }
        memset(t,0,sizeof(t));
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        memset(dis,0,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dijk(x+m,y+m);
    }
    return 0;
}
