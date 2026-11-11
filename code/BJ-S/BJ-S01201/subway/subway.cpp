#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define int long long
const int M=5e5+1;
int c,n,m,d,q,w[M],cnt,x,y,ans,vis[M],head[M];
struct node{
    int u,v,ut,vt,nxt,num;
}e[30001];
void add(int u,int v,int ut,int vt,int num){
    cnt++;
    e[cnt].u=u;
    e[cnt].v=v;
    e[cnt].ut=ut;
    e[cnt].vt=vt;
    e[cnt].num=num;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int u,int unum,int sum,int uth){
    if(u==y){
        ans=min(ans,sum+w[y]+uth);
        return;
    }
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(vis[v]){
            vis[v]=0;
            if(unum==0){
                dfs(v,e[i].num,sum+e[i].ut,e[i].vt);
            }else if(unum!=e[i].num){
                dfs(v,e[i].num,sum+e[i].ut+uth,e[i].vt);
            }else{
                dfs(v,unum,sum,e[i].vt);
            }
            vis[v]=1;
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
        int k;
        cin>>k;
        int u,ut;
        cin>>u>>ut;
        for(int j=1;j<=k-1;j++){
            int v,vt;
            cin>>v>>vt;
            add(u,v,ut,vt,i);
            add(v,u,vt,ut,i);
            u=v;
            ut=vt;
        }
    }
    while(q--){
        ans=0x3f3f3f3f;
        memset(vis,1,sizeof(vis));
        cin>>x>>y;
        vis[x]=0;
        dfs(x,0,w[x],0);
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}