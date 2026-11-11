#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;
struct edge{
    int to;
    bool w;
};
int c,t;
int n,k;
int d[1000005],dis[1000005],fa[1000005];
bool vis[1000005],v[1000005];
vector<edge> g[1000005],dg[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1,u,v;i^n;i++){
            cin>>u>>v;
            g[u].push_back({v,1});
            g[v].push_back({v,1});
            dg[u].push_back({v,1});
            dg[v].push_back({v,1});
            d[u]++,d[v]++;
        }cout<<n/(k+1)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
