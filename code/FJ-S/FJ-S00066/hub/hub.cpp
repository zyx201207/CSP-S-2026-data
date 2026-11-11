#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;

struct Edge{
    int u,v;
}edge[N];

int c,T,n,k,ones[1<<10],dis[N];
bool b[N];
vector<int> e[N];

void dfs(int x,int fa,int d){
    dis[x]=min(dis[x],d);
    for(int y:e[x])
        if(!b[y] && y!=fa)
            dfs(y,x,d+1);
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        for(int i=1;i<=n;i++) e[i].clear();
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            scanf("%d%d",&edge[i].u,&edge[i].v);
            e[edge[i].u].push_back(edge[i].v);
            e[edge[i].v].push_back(edge[i].u);
        }
        int ans=n;
        for(int i=1;i<1<<n;i++){
            ones[i]=ones[i-(i&(-i))]+1;
            if(ones[i]!=k) continue;
            for(int j=1;j<=n;j++)
                if((i>>j-1)&1)
                    b[j]=true;
                else
                    b[j]=false;
            int cnt=0;
            for(int j=1;j<n;j++)
                if(b[edge[j].u] && b[edge[j].v]) cnt++;
            if(cnt<k-2) continue;
            for(int i=1;i<=n;i++) dis[i]=N;
            for(int i=1;i<=n;i++)
                if(b[i])
                    dfs(i,0,0);
            int mx=0;
            for(int i=1;i<=n;i++)
                mx=max(mx,dis[i]);
            ans=min(ans,mx);
        }
        printf("%d\n",ans);
    }
    return 0;
}
