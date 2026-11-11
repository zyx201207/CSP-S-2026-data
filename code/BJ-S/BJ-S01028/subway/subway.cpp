#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define getchar getchar_unlocked

#define D 21
#define N 507
#define M 500007

template<typename T>inline void I(T &x){
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
}

template<typename T>inline void O(T x){
    if(!x) return putchar('0'),putchar('\n'),void();
    char c[20];int t=0;
    while(x) c[++t]=(x%10)|48,x/=10;
    while(t) putchar(c[t]),t--;
    putchar('\n');
}

namespace RTA{//FastIO!!!
    int n,m,dd,q,w[M],d[M],lin[M][D],t[M][D];
    LL dis[N][N];
    void main(){
        int c;
        I(c),I(n),I(m),I(dd),I(q);
        for(int i=1;i<=m;i++) I(w[i]);
        for(int i=1;i<=n;i++){
            int k;
            I(k);
            while(k--){
                int a,b;
                I(a),I(b);
                d[a]++;
                lin[a][d[a]]=i,t[a][d[a]]=b;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(j!=i) dis[i][j]=5e16;
        for(int i=1;i<=m;i++)
            for(int j1=1;j1<d[i];j1++){
                int l1=lin[i][j1];
                for(int j2=j1+1;j2<=d[i];j2++){
                    int l2=lin[i][j2];
                    dis[l1][l2]=dis[l2][l1]=min(dis[l1][l2],(LL)t[i][j1]+t[i][j2]);
                }
            }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        while(q--){
            int x,y;
            I(x),I(y);
            LL Ans=9e18,now=w[x]+w[y];
            for(int j1=1;j1<=d[x];j1++){
                int l1=lin[x][j1];
                now+=t[x][j1];
                for(int j2=1;j2<=d[y];j2++){
                    int l2=lin[y][j2];
                    now+=t[y][j2];
                    Ans=min(Ans,now+dis[l1][l2]);
                    now-=t[y][j2];
                }
                now-=t[x][j1];
            }
            O(Ans);
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    RTA::main();

    return 0;
}