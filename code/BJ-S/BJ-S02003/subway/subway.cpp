#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,n,m,d,q,k,maxn,w[500010],a[500010],tt[500010],vis[500010],s,t;
struct node{
    int x,w;
};
vector<node>g[510];
void spfa(int s){
    queue<int>q;
    memset(vis,0x3f,sizeof(vis));
    q.push(s);
    vis[s]=0;
    while(!q.empty()){
        int x=q.front();
        cout<<x<<endl;
        if(vis[x]){
            continue;
        }
        q.pop();
        for(auto v:g[x]){
            if(vis[x]+v.w<=vis[v.x]){
                vis[v.x]=vis[x]+v.w;
                q.push(v.x);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>tt[j];
        }
        for(int j=1;j<=k;j++){
            for(int l=j+1;l<=k;l++){
                g[a[j]].push_back({a[l],tt[j]+tt[l]});
                g[a[l]].push_back({a[j],tt[j]+tt[l]});
            }
        }
    }
    while(q--){
        cin>>s>>t;
        spfa(s);
        for(int i=1;i<=m;i++){
            cout<<vis[i]<<" ";
        }
        cout<<endl;
        cout<<w[s]+w[t]+vis[t]<<endl;
    }
    return 0;
}
