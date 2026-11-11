#include<bits/stdc++.h>
using namespace std;

const int N=505,M=500005;
vector<pair<int,int>>G[M];
long long W[M],dis[N][N],ans;
int Tid,n,m,D,q,Gtmp[25],Gtv[25];

template<typename qwq>inline void cmin(qwq &a,qwq b){(a>b)&&(a=b);}
template<typename qwq>inline void cmax(qwq &a,qwq b){(a<b)&&(a=b);}
template<typename qwq>inline void read(qwq &a){
    a=0;int c=getchar(),f=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) a=10*a+c-'0',c=getchar();
    if(f) a=-a;
}


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(Tid),read(n),read(m),read(D),read(q);
    for(int i=1;i<=m;i++) read(W[i]);
    for(int i=1;i<=m;i++) G[i].reserve(D);
    for(int i=1,k,a,t;i<=n;i++){
        read(k);
        for(int j=1;j<=k;j++){
            read(a),read(t),G[a].emplace_back(i,t);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        int u=G[i].size();
        for(int j=0;j<u;j++) Gtmp[j]=G[i][j].second;
        for(int j=0;j<u;j++) Gtv[j]=G[i][j].first;
        for(int j=0;j<u;j++){for(int k=0;k<u;k++){
            cmin(dis[Gtv[j]][Gtv[k]],0ll+Gtmp[j]+Gtmp[k]);
        }}
    }
    for(int k=1;k<=n;k++){for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cmin(dis[i][j],dis[i][k]+dis[k][j]);
    }}
    for(int z=1,x,y,a,b;z<=q;z++){
        read(x),read(y),ans=1e16;
        a=G[x].size(),b=G[y].size();
        for(int i=0;i<a;i++){for(int j=0;j<b;j++){
            long long t=dis[G[x][i].first][G[y][j].first];
            cmin(ans,t+G[x][i].second+G[y][j].second);
        }}
        printf("%lld\n",ans+W[x]+W[y]);
    }
    return 0;
}
/*
O(md^2+n^3+qd^2)
finish subway 15:08
code by Wxb2010
*/