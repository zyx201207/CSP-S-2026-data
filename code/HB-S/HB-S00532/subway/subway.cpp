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
#define mp(x,y) make_pair(x,y)
const int N=550;
const int M=5e5+50;
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
int cid,n,m,d,q;
ll w[M],edge[N][N];
vector<pair<int,ll> > passby[M]; 
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cid=read<int>(),n=read<int>(),m=read<int>(),d=read<int>(),q=read<int>();
    for(int i=1;i<=m;i++) w[i]=read<ll>();
    for(int i=1;i<=n;i++){
        int k=read<int>();
        while(k--){
            int station=read<int>();ll cost=read<ll>();
            passby[station].push_back(mp(i,cost));
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) edge[i][j]=LLM;
    for(int i=1;i<=n;i++) edge[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int d1=0;d1<(int)passby[i].size();d1++)
            for(int d2=d1+1;d2<(int)passby[i].size();d2++){
                int x=passby[i][d1].first,y=passby[i][d2].first;
                edge[x][y]=edge[y][x]=min(edge[x][y],passby[i][d1].second+passby[i][d2].second);
            }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++){
            if(i==k) continue ;
            for(int j=1;j<=n;j++){
                if(j==i||j==k) continue ;
                edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
            }
        }
    while(q--){
        int x=read<int>(),y=read<int>();ll ans=LLM;
        for(int d1=0;d1<(int)passby[x].size();d1++) for(int d2=0;d2<(int)passby[y].size();d2++) ans=min(ans,edge[passby[x][d1].first][passby[y][d2].first]+passby[x][d1].second+passby[y][d2].second);
        ans+=w[x]+w[y];
        write<ll>(ans);hh
    }
    return 0;
}
/*
g++ subway.cpp -o S -O2 -std=c++14 -Wall
./S
time ./S

*/