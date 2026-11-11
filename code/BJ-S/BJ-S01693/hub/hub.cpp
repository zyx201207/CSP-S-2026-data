#include<bits/stdc++.h>
using namespace std;
const int N=4005;
int dep[N];
int fa[N][25];
int c,t;
int n,k;
vector<int> edge[N*2];
void dfs(int u,int fath){
    dep[u]=dep[fath]+1;
    fa[u][0]=fath;
    for(int i=1;i<=20;i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(int v : edge[u]){
        if(v==fath) continue;
        dfs(v,u);
    }
}
int LCA(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    while(dep[a]!=dep[b]){
        int k=log2(dep[a]-dep[b]);
        a=fa[a][k];
    }
    if(a==b){
        return a;
    }
    for(int i=20;i>=1;i--){
        if(fa[a][i]!=fa[b][i]){
            a=fa[a][i];
            b=fa[b][i];
        }
    }
    return fa[a][0];
}
bool S[N];
bool vis[N];
void check(int u){
    vis[u]=true;
    for(int v : edge[u]){
        if(vis[v]||!S[v]) continue;
        check(v);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--){
        for(int i=1;i<=n;i++){
            edge[i].clear();
        }
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n-1;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dep[0]=0;
        fa[0][0]=0;
        dfs(1,0);
        //printf("%d\n",LCA(3,4));
        int ans=1e9;
        for(int s=0;s<=(1<<n)-1;s++){
            int maxs=0;
            int num=0;
            for(int i=1;i<=n;i++){
                vis[i]=false;
                if((s>>(i-1))&1){
                    S[i]=true;
                    num++;
                }
                else{
                    S[i]=false;
                }
            }
            if(num!=k) continue;
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(S[i]&&!vis[i]){
                    check(i);
                    cnt++;
                }
            }
            if(cnt>2) continue;
            for(int i=1;i<=n;i++){
                if(S[i]==true) continue;
                int minn=1e9;
                for(int j=1;j<=n;j++){
                    if(S[j]==false) continue;
                    int lca=LCA(i,j);
                    int len=dep[i]+dep[j]-2*dep[lca];
                    //printf("%d %d %d\n",i,j,len);
                    minn=min(minn,len);
                }
                maxs=max(maxs,minn);
            }
            //printf("%d %d\n",s,maxs);
            ans=min(ans,maxs);
        }
        printf("%d\n",ans);
    }
}
