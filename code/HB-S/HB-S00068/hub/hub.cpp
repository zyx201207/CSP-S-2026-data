#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int cid,T,n,k,book[N],f[N],dis[N];
vector<int>v[N];
void dfs(int x,int fa){
    f[x]=fa;
    for(int u:v[x]){
        if(u==fa)continue;
        dfs(u,x);
    }
}
int q[N],head,tail;
namespace K1{
    int P,Q,md,ans;
    int dfs(int x,int fa){
        int d1=0,d2=0;
        for(int u:v[x]){
            if(u==P&&x==Q||u==Q&&x==P||u==fa)continue;
            int t=dfs(u,x)+1;
            if(t>d1)d2=d1,d1=t;
            else d2=t;
        }
        md=max(md,d1+d2);
        return md;
    }
    void dfs2(int x,int fa){
        for(int u:v[x]){
            if(u==fa)continue;
            P=u,Q=x;
            md=0;
            int tmp=0;
            dfs(x,0);
            tmp=max(tmp,(md+1)>>1);
            md=0;
            dfs(u,0);
            tmp=max(tmp,(md+1)>>1);
            ans=min(ans,tmp);
            dfs2(u,x);
        }
    }
    void main(){
        md=0;
        dfs(1,0);
        ans=md>>1;
        dfs2(1,0);
        printf("%d\n",ans);
    }
}
void WZH(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)v[i].clear();
    for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
    if(cid==7)return K1::main();
    dfs(1,0);
    int ans=n+1;
    for(int i=0;i<(1<<n);i++){
        if(__builtin_popcount(i)!=k)continue;
        for(int j=1;j<=n;j++)if((i>>j-1)&1)book[j]=1;else book[j]=0;
        int cnt=0;
        for(int j=1;j<=n;j++)cnt+=(book[j]==1&&book[f[j]]==0);
        if(cnt>2)continue;
        int maxn=0;
        for(int j=1;j<=n;j++){
            head=tail=0;
            for(int p=1;p<=n;p++)dis[p]=-1;
            q[tail++]=j;
            dis[j]=0;
            while(head<tail){
                int x=q[head++];
                if(book[x]){maxn=max(maxn,dis[x]);break;}
                for(int u:v[x]){
                    if(~dis[u])continue;
                    dis[u]=dis[x]+1;
                    q[tail++]=u;
                }
            }
        }
        ans=min(ans,maxn);
    }
    printf("%d\n",ans);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&cid,&T);
    while(T--)WZH();
    return 0;  
}