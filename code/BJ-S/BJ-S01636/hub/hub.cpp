#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
const int maxm=1005;
const int inf=1e9;
int c,t,n,k,d[maxm][maxm],eu[maxn],ev[maxn],dep[maxn];
vector<int> g[maxn];
void add(int u,int v){
    g[u].push_back(v);
}

void dfs(int u,int fa){
    for(auto v:g[u]){
        if(v==fa) continue;
        dep[v]=dep[u]+1,dfs(v,u);
    }
}

int ch[maxn],ans=inf;

struct DSU{
    int f[maxn];
    void init(){
        for(int i=1;i<=n;i++) f[i]=i;
    }
    int find(int i){
        return f[i]==i?f[i]:f[i]=find(f[i]);
    }
    void merge(int i,int j){
        int a=find(i),b=find(j);
        if(a!=b) f[a]=b;
    }
}dsu;
int check(){
    int cnt0=0,cnt=0;
    for(int i=1;i<=n;i++) cnt0+=(ch[i]==1?1:0);
    if(cnt0!=k) return inf;
    for(int i=1;i<=n-1;i++){
        if(ch[eu[i]]==1 && ch[ev[i]]==1) cnt++;
    }
    if(cnt<k-2) return inf;

    int res=0;
    for(int i=1;i<=n;i++){
        dep[i]=0,dfs(i,0);
        int tot=inf;
        for(int j=1;j<=n;j++){
            if(ch[j]==1) tot=min(tot,dep[j]);
        }
        res=max(res,tot);
    }
    return res;
}
void dfs2(int m){
    if(m==n+1){
        ans=min(ans,check());
        return;
    }
    ch[m]=0,dfs2(m+1);
    ch[m]=1,dfs2(m+1);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n-1;i++){
            scanf("%d%d",&eu[i],&ev[i]),add(eu[i],ev[i]),add(ev[i],eu[i]);
        }
        if(c==7){
            for(int i=1;i<=n;i++){
                dep[i]=0,dfs(i,0);
                for(int j=1;j<=n;j++) d[i][j]=dep[j];
            }
            int ans=1e9;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    int res=0;
                    for(int k=1;k<=n;k++) res=max(res,min(d[i][k],d[j][k]));
                    ans=min(ans,res);
                }
            }
            printf("%d\n",ans);
        }
        else{
            ans=1e9,dfs2(1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
