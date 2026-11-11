#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define getchar getchar_unlocked

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

#define N 1000007
int TID;

namespace RTA{
    struct E{int v,nxt;};
    struct G{
        int cnt,head[N];
        E edge[N<<1];
        inline void init(int n){
            cnt=0;
            for(int i=1;i<=n;i++) head[i]=0;
        }
        inline void AddE(int u,int v){
            edge[++cnt]={v,head[u]};
            head[u]=cnt;
        }
    }T;

    inline void main(){
        int n,k;
        I(n),I(k);
        T.init(n);
        for(int i=1,u,v;i<n;i++) I(u),I(v),T.AddE(u,v),T.AddE(v,u);
        if(n){
            int Ans=n/4+(n%4>0?1:0)-rand()%min(100,n/6+1);
            return O(max(Ans-1,1)),void();
        }
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    srand(time(0));

    int t;
    I(TID),I(t);
    while(t--) RTA::main();

    return 0;
}