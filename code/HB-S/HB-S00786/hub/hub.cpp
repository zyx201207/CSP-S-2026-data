#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
template<typename tp> inline void cmin(tp &a,tp b){(b<a)&&(a=b);}
template<typename tp> inline void cmax(tp &a,tp b){(b>a)&&(a=b);}
template<typename tp> inline void read(tp &x){
    x=0;tp f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch^48);ch=getchar();}
    x*=f;
}
template<typename tp> inline void write(tp x,char ed=' '){
    static char stk[40];
    int top=0;
    if(x<0) putchar('-'),x=-x;
    do stk[++top]=x%10+48,x=x/10; while(x);
    while(top) putchar(stk[top--]);
    putchar(ed);
}
void mian(){
    int n,k;
    read(n);
    read(k);
    vector<vector<int>> G(n);
    for(int i=1;i<n;i++){
        int u,v;
        read(u);
        read(v);
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto dfs=[&](auto self,int u,int fa,vector<int> &dis) -> void {
        for(auto v:G[u])if(v!=fa){
            dis[v]=dis[u]+1;
            self(self,v,u,dis);
        }
    };
    vector<vector<int>> dis(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dfs(dfs,i,-1,dis[i]);
    }
    int ans=INT_MAX;
    for(int S=0;S<(1<<n);S++){
        if(__builtin_popcount(S)!=k) continue;
        int res=0;
        vector<bool> vis(n,false);
        auto dfs2=[&](auto self,int u,int fa) -> void {
            if(!((1<<u)&S)){
                return ;
            }
            if(vis[u]) return;
            vis[u]=true;
            for(auto v:G[u])if(v!=fa){
                self(self,v,u);
            }
        };
        int cnt=0;
        for(int i=0;i<n;i++){
            if(((1<<i)&S)&&!vis[i]){
                cnt++;
                dfs2(dfs2,i,-1);
            }
        }
        if(cnt>2) continue;
        for(int i=0;i<n;i++)if(!((1<<i)&S)){
            int tt=INT_MAX;
            for(int j=0;j<n;j++)if(1<<j&S){
                cmin(tt,dis[i][j]);
            }
            cmax(res,tt);
        }
        cmin(ans,res);
    }
    write(ans,'\n');
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int _c,_t;
    read(_c);
    read(_t);
    while(_t--){
        mian();
    }
    return 0;
}