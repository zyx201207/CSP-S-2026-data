#include<bits/stdc++.h>
#define LL long long
#define Uint unsigned int
#define ULL unsigned LL
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define fr first
#define se second
#define pb push_back
#define isr insert
#define _i128 __int128
using namespace std;
const int N = 1e6+5;
int caseid,T,n,k;
int Fa[N],dep[N],fa[N],Ans;
vector<int> g[N];
int read(){
    int su=0,pp=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')pp=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){su=su*10+ch-'0';ch=getchar();}
    return su*pp;
}
void DFS(int u,int Fath){
    Fa[u]=Fath,dep[u]=dep[Fath]+1;
    for(int v:g[u])if(v^Fath)DFS(v,u);return;
}
int FF(int u){return (fa[u]==u?u:fa[u]=FF(fa[u]));}
int pop_c(int num){
    int cnt=0;
    while(num)cnt+=num%2,num/=2;
    return cnt;
}
bool check(int num){
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)if((num>>i-1)&1)
        for(int j:g[i])if((num>>j-1)&1){
            int u=FF(i),v=FF(j);
            if(u!=v)fa[u]=v;
        }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(((num>>i-1)&1)&&FF(i)==i)cnt++;
    return (cnt<=2);
}
int road(int u,int v){
    int cnt=0;
    while(u!=v){
        if(dep[u]<dep[v])swap(u,v);
        u=Fa[u],++cnt;
    }
    return cnt;
}
int sol(int num){
    int ans=0;
    for(int i=1;i<=n;i++){
        int res=n;
        for(int j=1;j<=n;j++)
            if((num>>j-1)&1)res=min(res,road(i,j));
        ans=max(ans,res);
    }
    return ans;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    caseid=read(),T=read();
    while(T--){
        n=read(),k=read();
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            g[u].pb(v),g[v].pb(u);
        }
        dep[0]=0;DFS(1,0);
        Ans=n;
        for(int st=0;st<(1<<n);st++){
            if(pop_c(st)!=k)continue;
            if(check(st))Ans=min(Ans,sol(st));
        }
        cout<<Ans<<"\n";
    }
    return 0;
}
//rp++
//我是说 倘若活过一百万次仍脆弱 的我 能待在你身边吗 ——《猫是猫的猫》
