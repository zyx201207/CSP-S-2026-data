#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ill __int128
#define hh putchar(10);
#define lc(k) st[k].lc
#define rc(k) st[k].rc
#define LLM (ll)1e17
#define IM (int)1e9
#define mids (nl+nr)>>1
#define set_it set<int>::iterator
#define map_it map<int,int>::iterator
const int N=5e5+50;
template<class T>
inline T read(){
    T x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
template<class T>
inline void write(T ans){
    if(ans<0){putchar('-');write<T>(-ans);}
    else if(ans<10) putchar(ans+'0');
    else{write<T>(ans/10);putchar(ans%10+'0');}
    return ;
}
int dis[20][20],n,K,cid,t,ans=IM,fa[N];
int get(int x){
    if(fa[x]==x) return x;
    else return fa[x]=get(fa[x]);
}
bool key[20];
vector<int> g[N];
void dfs1(int root,int x,int f,int dep){
    dis[root][x]=dep;
    for(int i=0;i<(int)g[x].size();i++){
        int y=g[x][i];
        if(y==f) continue ;
        dfs1(root,y,x,dep+1);
    }
    return ;
}
void dfs2(int k,int cnt){
    if(cnt>K) return ;
    if(k==n+1){
        if(cnt!=K) return ;
        int cnt_block=0;
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<=n;i++){
            if(!key[i]) continue ;
            for(int pi=0;pi<(int)g[i].size();pi++){
                if(!key[g[i][pi]]) continue ;
                int rx=get(i),ry=get(g[i][pi]);
                if(rx!=ry) fa[ry]=rx;
            }
        }
        for(int i=1;i<=n;i++) if(key[i]&&get(i)==i) cnt_block++;
        if(cnt_block>2) return ;
        int maxd=0;
        for(int i=1;i<=n;i++) if(!key[i]){
            int mindis=IM;
            for(int j=1;j<=n;j++) if(key[j]) mindis=min(mindis,dis[i][j]);
            maxd=max(maxd,mindis);
        }
        ans=min(ans,maxd);
        return ;
    }
    key[k]=1;dfs2(k+1,cnt+1);
    key[k]=0;dfs2(k+1,cnt);
    return ;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cid=read<int>(),t=read<int>();
    while(t--){
        n=read<int>(),K=read<int>();
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n-1;i++){
            int x=read<int>(),y=read<int>();
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if(13<=cid&&cid<=14){
            int tn=(n-1)/2;
            int tans=0;
            if(K==n) tans=0;
            else if(K>=tn) tans=1;
            else{
                int tk=(K%2==0?K/2:(K-1)/2),ttn=(tn&2==0?tn/2:(tn-1)/2);
                tans=max(tans,ttn/2-tk/2+1);
                tk=K-tk,ttn=tn-ttn;
                tans=max(tans,ttn/2-tk/2+1);
            }
            write<int>(tans);hh
        }
        else{
            for(int i=1;i<=n;i++) dfs1(i,i,0,0);
            ans=IM;
            dfs2(1,0);
            write<int>(ans);hh
        }
    }
    return 0;
}
/*
g++ hub.cpp -o H -O2 -std=c++14 -Wall
./H
time ./H

*/