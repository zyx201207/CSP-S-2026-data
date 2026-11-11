#include<bits/stdc++.h>
using namespace std;
namespace IO{
    template<typename T>inline void read(T&x){
        x=0;char c=getchar();bool f=0;
        while(!isdigit(c)) f|=(c=='-'),c=getchar();
        while(isdigit(c)) x=x*10-(c-'0'),c=getchar();
        !f?(x=-x):0;
    }
    template<typename T>inline void write(T x){
        if(x==0){putchar('0');return ;}
        if(x>0) x=-x;
        else putchar('-');
        int st[20],top=0;
        while(x) st[++top]=x%10,x/=10;
        while(top) putchar('0'-st[top--]);
    }
    inline void read(char&x){x=getchar();while(isspace(x)) x=getchar();}
    inline void write(char x){putchar(x);}
    inline void read(string&s){
        s.clear();char c;read(c);
        while(!isspace(c)&&~c) s+=c,c=getchar();
    }
    inline void write(string s){for(int i=0,len=s.size();i<len;i++) putchar(s[i]);}
    template<typename T>inline void write(T*x){while(*x) putchar(*x++);}
    template<typename T,typename...T2>inline void read(T&x,T2&...y){read(x),read(y...);}
    template<typename T,typename...T2>inline void write(const T&x,const T2&...y){write(x),putchar(' '),write(y...),sizeof...(y)==1?putchar('\n'):0;}
}using namespace IO;
const int maxn=1000010,inf=1000000000;
int n,k,sz[maxn],deep[maxn],len,ans,dis[maxn];
bool chosed[maxn],vis[maxn];
vector<int>e[maxn];
struct node{
    int val[2][3];
    node(){val[0][0]=val[0][1]=val[0][2]=val[1][0]=val[1][1]=val[1][2]=inf;}
}f[110][110][110];
void dfs(int u){
    for(int v:e[u]){
        if(vis[v]) continue;
        if(!chosed[v]) continue;
        vis[v]=1;
        dfs(v);
    }
}
void calc(){
    queue<int>q;
    int cnt=0;
    for(int i=1;i<=n;i++) vis[i]=0;
    int g=0;
    for(int i=1;i<=n;i++){
        if(!chosed[i]) continue;
        if(vis[i]) continue;
        if(++g>2) return ;
        dfs(i);
    }
    for(int i=1;i<=n;i++) if(chosed[i]) q.push(i),dis[i]=0,cnt++;else dis[i]=inf;
    if(cnt!=k) return ;
    int maxx=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        maxx=max(maxx,dis[u]);
        if(maxx>=ans) return ;
        for(int v:e[u]){
            if(dis[v]<=dis[u]+1) continue;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
    ans=maxx;
}
void solve(){
    for(int i=1;i<=n;i++) e[i].clear();
    read(n,k);
    for(int i=1;i<n;i++){
        int u,v;read(u,v);
        e[u].push_back(v),e[v].push_back(u);
    }
    if(k==n){write(0);return ;}
    ans=inf;
    if(k==2){
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
            for(int ano=1;ano<=n;ano++) chosed[ano]=0;
            chosed[i]=chosed[j]=1;
            calc();
        }
        write(ans);
        return ;
    }
    for(int s=0;s<(1<<n);s++){
        for(int i=1;i<=n;i++) chosed[i]=(s&(1<<i-1));
        calc();
    }
    write(ans);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int testid,T;read(testid,T);
    while(T--) solve(),write("\n");
    return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/