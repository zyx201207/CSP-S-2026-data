#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,M=3e6+10;
typedef long long LL;
int c,t;
LL a[N];
int n;
LL d;
struct node {
    int to,next;
} e[M];
int pre[N],k=0;
inline void add(int u,int v) {
    e[++k]={v,pre[u]};
    pre[u]=k;
}
bool vis[N];
int dis[N];
int dp[N];
void bfs(int s) {
    queue<int> q;
    q.push(s);
    for(int i=1;i<=n;i++) vis[i]=false,dis[i]=0,dp[i]=0;
    vis[s]=true;
    dp[s]=1;
    while(!q.empty()) {
        int p=q.front();
        q.pop();
        for(int i=pre[p];i;i=e[i].next) {
            int to=e[i].to;
            if(!vis[to]) {
                vis[to]=true;
                dis[to]=dis[p]+1;
                q.push(to);
            }
            if(dis[to]==dis[p]+1) dp[to]+=dp[p];
        }
    }
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--) {
        scanf("%d%lld",&n,&d);
        k=0;
        for(int i=1;i<=n;i++) {
            scanf("%lld",&a[i]);
            pre[i]=0;
        }
        for(int i=1;i<=n;i++) {
            int l=lower_bound(a+1,a+n+1,a[i]-d)-a;
            int r=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
            for(int j=l;j<=r;j++) {
                if(i!=j) add(i,j);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            bfs(i);
            for(int j=1;j<=n;j++) {
                if(dp[j]==2) ans++;
            }
        }
        printf("%d\n",ans >> 1);
    }
    return 0;
}
