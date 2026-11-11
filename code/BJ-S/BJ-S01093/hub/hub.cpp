#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> e[N];
int dis[N];
int mx;
int u,v;
void dfs1(int x,int fa){
    for(int i:e[x]){
        if(i==fa) continue;
        dis[i]=dis[x]+1;
        if(dis[i]>mx){
            mx=dis[i];
            u=i;
        }
        dfs1(i,x);
    }
}
void dfs2(int x,int fa){
    for(int i:e[x]){
        if(i==fa) continue;
        dis[i]=dis[x]+1;
        if(dis[i]>mx){
            mx=dis[i];
            v=i;
        }
        dfs2(i,x);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        dis[1]=0;
        mx=0;
        dfs1(1,0);
        dis[u]=0;
        mx=0;
        dfs2(u,0);
        cout<<(abs(mx-k)+1)/2<<endl;
        for(int i=1;i<=n;i++)
            e[i].clear();
    }
    return 0;
}
