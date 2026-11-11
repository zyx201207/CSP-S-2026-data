#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll u,n,m,d,q,w[500010],c[510][510];
vector<array<ll,2>> e[500010],v[50];
struct node{
    ll u,w;
};
ll spfa(ll x,ll y){
    ll dis[50];
    memset(dis,0x3f3f3f3f,sizeof(dis));
    ll ans=1e9;
    queue<node> q;
    for(int i=0;i<e[x].size();i++){
        ll v1=e[x][i][0];
        ll w=e[x][i][1];
        dis[v1]=w;
        q.push({v1,dis[v1]});
    }
    while(!q.empty()){
        node now=q.front();
        q.pop();
        for(int i=0;i<v[now.u].size();i++){
            ll v1=v[now.u][i][0];
            ll w=v[now.u][i][1];
            if(dis[v1]>dis[now.u]+w){
                dis[v1]=dis[now.u]+w;
                q.push({v1,dis[v1]});
            }
        }
    }
    for(int j=0;j<e[y].size();j++){
        ans=min(ans,dis[e[y][j][0]]+e[y][j][1]);
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>u>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=0;i<n;i++){
        ll k;
        cin>>k;
        for(int j=1;j<=k;j++){
            ll u,w;
            cin>>u>>w;
            e[u].push_back({i,w});
        }
    }
    memset(c,0x3f3f3f3f,sizeof(c));
    for(int i=1;i<=m;i++){
        for(int j=0;j<e[i].size();j++){
            for(int p=j+1;p<e[i].size();p++){
                if(c[e[i][j][0]][e[i][p][0]]>e[i][j][1]+e[i][p][1]){
                    c[e[i][j][0]][e[i][p][0]]=e[i][j][1]+e[i][p][1];
                }
                if(c[e[i][p][0]][e[i][j][0]]>e[i][p][1]+e[i][j][1]){
                    c[e[i][p][0]][e[i][j][0]]=e[i][p][1]+e[i][j][1];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            v[i].push_back({j,c[i][j]});
            v[j].push_back({i,c[i][j]});
        }
    }
    for(int i=1;i<=q;i++){
        ll g,h;
        cin>>g>>h;
        cout<<spfa(g,h)+w[g]+w[h]<<endl;
    }
    return 0;
}
