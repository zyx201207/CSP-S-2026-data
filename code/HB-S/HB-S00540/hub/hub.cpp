#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k;
vector<int> g[N];
int maxdis,far;
void dfs(int u,int fa,int dis){
    if(dis>maxdis){
        maxdis=dis;
        far=u;
    }
    for(int v:g[u]){
        if(v==fa) continue;
        dfs(v,u,dis+1);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(c==13||c==14){
            cout<<(n+3-k+7)/8<<'\n';
        }
        else if(c==7||c==11||c==12){
            maxdis=0;far=0;
            dfs(1,0,0);
            int a=far;
            maxdis=0;
            dfs(a,0,0);
            cout<<(maxdis+3)/4<<'\n';
        }
        else{
            maxdis=0;far=0;
            dfs(1,0,0);
            int a=far;
            maxdis=0;
            dfs(a,0,0);
            cout<<(maxdis+3)/2<<'\n';
        }
    }
    return 0;
}