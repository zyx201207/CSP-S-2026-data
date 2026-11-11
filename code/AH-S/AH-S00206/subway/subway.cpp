#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,shu;
int w[500005],k[5005];
int g[5005][5005];
int v[5005][5005],a[5005][5005];
bool f[5005][5005],vis[5005];
struct node{
    int v,w;
};
int bfs(int st,int en){
    vis[st]=1;
    queue<node> q;
    q.push({st,0});
    while(!q.empty()){
        node t=q.front();
        q.pop();
        if(t.v==en) return t.w;
        for(int i=1;i<=k[t.v];i++){
            q.push({a[t.v][i],t.w+1});
        }
    }
    return 0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int shua,shub;
            cin>>shua>>shub;
            a[i][j]=shua;
            v[i][shua]=shub;
            shu=shub;
            f[i][j]=1;
        }
    }
    while(p--){
        int x,y;
        cin>>x>>y;
        memset(vis,0,sizeof(vis));
        cout<<bfs(x,y)*shu<<endl;
    }
    return 0;
}
