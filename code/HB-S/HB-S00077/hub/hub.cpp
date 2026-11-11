#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define x first
#define y second
inline ll read(){
    ll d=0,f=0;char ch=getchar();
    while (!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) d=d*10+ch-'0',ch=getchar();
    return f?-d:d;
}
const int N=1000005,M=500050;

int n,k,h[N],idx=1,e[N<<1],ne[N<<1];
inline void add(int a,int b) {e[idx]=b,ne[idx]=h[a],h[a]=idx++;}

bool vis[N];
int fa[N],sz[N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){
    x=find(x),y=find(y);
    if (x==y) return ;
    fa[x]=y,sz[y]|=sz[x];
}

inline bool check(){
    for (int i=1;i<=n;i++) fa[i]=i,sz[i]=vis[i];
    for (int u=1;u<=n;u++) if (vis[u]){
        for (int i=h[u];i;i=ne[i]){
            int v=e[i];
            if (vis[v]) merge(u,v);
        }
    }
    int cnt=0;
    for (int i=1;i<=n;i++)if (find(i)==i) cnt+=sz[i];
    return cnt>2;
}

queue  <int> q;
int d[N];
inline int bfs(){
    for (int i=1;i<=n;i++) if (vis[i]) q.push(i),d[i]=0;else d[i]=1e9;
    int  mx=0;
    while (q.size()){
        int u=q.front();q.pop();
        mx=max(mx,d[u]);
        for (int i=h[u];i;i=ne[i]){
            int v=e[i];
            if (d[v]==1e9) {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return mx;
}

inline void solveB(){
    n=read(),k=read(),idx=1;
    for (int i=1;i<=n;i++) h[i]=0;
    for (int i=1;i<n;i++) {
        int u=read(),v=read();
        add(u,v),add(v,u);
    }
    int ans=n;
    for (int i=(1<<k)-1;i<(1<<n);i++){
        int sum=0;
        for (int j=1;j<=n;j++) if ((i>>j-1)&1) vis[j]=1,sum++;else vis[j]=0;
        if (sum!=k) continue;
        if (check()) continue;
        // for (int j=1;j<=n;j++) if(vis[j]) printf("%d ",j);puts("");
        ans=min(bfs(),ans);
    }
    printf("%d\n",ans);
}

inline void solve(){
    n=read(),k=read(),idx=1;
    for (int i=1;i<=n;i++) h[i]=0;
    for (int i=1;i<n;i++) {
        int u=read(),v=read();
        add(u,v),add(v,u);
    }
    if (n==k) puts("0");
    else puts("1");
}

inline void solveA(){
    n=read(),k=read();
    for (int i=1;i<n;i++) {
        int u=read(),v=read();
    }
    if (n==k) {puts("0");return ;}
    int m=(n-1)/2;
    if (k>=m) {puts("1");return ;}
    int res=m+2-k;
    if (res%4==0||res%4==3) printf("%d\n",max((res+3)/4+1,1));
    else printf("%d\n",max((res+3)/4,1));
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    // auto st=clock();
    int c=read(),T=read();
    while (T--) {
        if (c>=13&&c<=14) solveA();
        else if (c<=3) solveB();
        else solve();
    }
    // cerr<<"cost:"<<1000*(clock()-st)/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}