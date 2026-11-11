#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 2147483647
#define N 50005
LL c,n,m,d,q,k,s,e;
LL w[N],di[N],vis[N];
vector<LL> mp[N],way[N];
void dijkstra(LL x){
    for(LL i=1;i<=m;i++){
        di[i]=INF;
    }
    memset(vis,0,sizeof(vis));
    di[x]=0;
    priority_queue<pair<int,LL>> pq;
    pq.push(make_pair(0,x));
    while(!pq.empty()){
        LL u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(LL i=0;i<mp[u].size();i+=2){
            LL v=mp[u][i],w=mp[u][i+1];
            if(di[u]+w<di[v]){
                di[v]=di[u]+w;
                pq.push(make_pair(-di[v],v));
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(LL i=1;i<=m;i++){
        cin>>w[i];
    }
    for(LL i=1;i<=n;i++){
        cin>>k;
        way[i].push_back(k);
        for(LL j=1;j<=k;j++){
            LL x,y;
            cin>>x>>y;
            way[i].push_back(x);
            way[i].push_back(y);
        }
        for(LL j=1;j<way[i].size();j+=2){
            for(LL k=j+2;k<way[i].size();k+=2){
                if(j==k)continue;
                LL u=way[i][j],v=way[i][k],w1=way[i][j+1],w2=way[i][k+1];
                //cout<<u<<" "<<v<<" "<<w1+w2<<endl;
                mp[u].push_back(v);
                mp[u].push_back(w1+w2);
                mp[v].push_back(u);
                mp[v].push_back(w1+w2);
            }
        }
    }
    while(q--){
        cin>>s>>e;
        dijkstra(s);
        cout<<w[s]+w[e]+di[e]<<endl;
    }
    return 0;
}
