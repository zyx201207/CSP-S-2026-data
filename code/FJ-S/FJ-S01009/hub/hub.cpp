#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll sum=0,f=1; char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-f;
    for(;'0'<=c&&c<='9';c=getchar()) sum=(sum<<1)+(sum<<3)+c-'0';
    return sum*f;
}
inline int Min(int x,int y){return x<y?x:y;}
inline int Max(int x,int y){return x>y?x:y;}
/*-----------------*/
int c_;
namespace sub1{
    const int N=4010;
    int T,n,k,dp[N][N],L;
    vector<int> e[N];
    inline int dfs(int u,int fa,int rt){
        int d=0;
        for(auto v:e[u]){
            if(v==fa) continue;
            d=Max(d,dfs(v,u,rt)+1);
            dp[rt][u]+=dp[rt][v];
        }
        if(d>=L||u==rt) dp[rt][u]++;
        return d;
    }
    int d[N],md[N],sum;
    inline void init(int u,int fa){
        md[u]=d[u]=d[fa]+1;
        for(auto v:e[u]){
            if(v==fa) continue;
            init(v,u);
            md[u]=Max(md[u],md[v]);
        }
    }
    inline void Dfs(int u,int fa,int rt,int x,int mx){
        int y=dp[u][u]-dp[u][fa];
        if(mx>L) return;
        // printf("%d %d %d %d : %d %d\n",u,fa,rt,mx,x,y);
        sum=Min(sum,x+y);

        int X=d[u],Y=d[u];
        for(auto v:e[u]){
            if(v==fa) continue;
            if(md[v]>=X) Y=X,X=md[v];
            else if(md[v]>Y) Y=md[v];
        }
        // printf("%d %d %d\n",d[u],X,Y);
        for(auto v:e[u]){
            if(v==fa) continue;
            int D=(md[v]==X?Y:X),tmx=mx;
            if(D>L) tmx=Max(tmx,D-d[u]);
            Dfs(v,u,rt,x,tmx+1);
        }
    }
    inline bool check(int mid){
        L=mid,sum=N;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dp[i][j]=0;
        for(int i=1;i<=n;i++) dfs(i,0,i);
        // for(int i=1;i<=n;i++)
        // for(int j=1;j<=n;j++) printf("%d %d : %d\n",i,j,dp[i][j]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) d[j]=md[j]=0;
            for(auto v:e[i]){
                init(v,i);
                Dfs(v,i,i,dp[i][i]-dp[i][v],-N);
            }
        }
        return sum>k;
    }
    inline void solve(){
        n=read();k=read();
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            u=read();v=read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(n==k){
            printf("0\n");
            return;
        }
        // check(1);
        // return;
        int l=1,r=n,ans=n;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid)) l=mid+1;
            else r=mid-1,ans=mid;
        }
        printf("%d\n",ans);
    }
    inline void mian(){
        T=read();
        while(T--) solve();
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c_=read();
    sub1::mian();
    return 0;
}