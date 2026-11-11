#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct node{
    int v,t;
};
vector <node> a[500050];
int g[5050][5050];
int w[500050];
int vis[500050];
int x,y;
int c,n,m,d,p,ans;
int i,j;

void add_node(int u,int v,int t){
    node new_node;
    new_node.v=v;
    new_node.t=t;
    a[u].push_back(new_node);
    new_node.v=u;
    new_node.t=t;
    a[v].push_back(new_node);
    return ;
}

void dfs(int x,int dep,int st,int ed){
    int sum=0;
    int i,v;
    //cout<<x<<endl;
    if(dep>=ans){
        return ;
    }

    g[x][st]=min(dep,g[x][st]);
    g[st][x]=g[x][st];

    if(g[x][ed]!=0x7fffffff){
        ans=min(ans,g[x][ed]+dep);
        return ;
    }

    if(x==ed){
        ans=min(ans,dep);
        return ;
    }


    vis[x]=1;
    for(i=0;i<a[x].size();i++){
        v=a[x][i].v;
        if(!vis[v]){
            dfs(v,dep+a[x][i].t,st,ed);
        }
    }
    vis[x]=0;
    return ;
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>p;
    for(i=1;i<=n;i++){
        cin>>w[i];
    }
    for(i=1;i<=m;i++){
        int k;
        cin>>k;
        n++;
        for(j=1;j<=k;j++){
            int v,t;
            cin>>v>>t;
            add_node(n,v,t);
        }
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            g[i][j]=0x7fffffff;
            g[j][i]=0x7fffffff;
        }
        g[i][i]=0;
    }

    for(i=1;i<=p;i++){
        cin>>x>>y;
        ans=0x7fffffff;
        //printf("%d -> %d:\n",x,y);
        dfs(x,0,x,y);
        //cout<<ans<<endl;
        cout<<w[x]+w[y]+ans<<endl;
    }
    return 0;
}
