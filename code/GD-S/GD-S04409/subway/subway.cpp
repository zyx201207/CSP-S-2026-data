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
#define LL long long
const int maxn=510,maxm=500010;
const LL inf=1000000000000000000;
int testid,n,m,d,q;
LL dis[maxn][maxn],w[maxm];
vector<pair<int,LL>>hv[maxm];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(testid,n,m,d,q);
    for(int i=1;i<=m;i++) read(w[i]);
    for(int i=1;i<=n;i++){
        int k;read(k);
        for(int j=1;j<=k;j++){
            int a,t;read(a,t);
            hv[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=((i==j)?0:inf);
    for(int i=1;i<=m;i++){
        for(pair<int,LL>to:hv[i]) for(pair<int,LL>too:hv[i]){
            int u=to.first,v=too.first;LL t=to.second+too.second;
            dis[u][v]=dis[v][u]=min(dis[u][v],t);
        }
    }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++){
        if(dis[i][k]>=inf) continue;
        for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    while(q--){
        int be,en;read(be,en);
        LL ans=inf;
        for(pair<int,LL>st:hv[be]) for(pair<int,LL>ed:hv[en]){
            int u=st.first,v=ed.first;
            LL t=st.second+ed.second+w[be]+w[en];
            ans=min(ans,dis[u][v]+t);
        }
        write(ans),write("\n");
    }
    return 0;
}