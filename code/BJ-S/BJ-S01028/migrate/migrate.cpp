#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define getchar getchar_unlocked

template<typename T>inline void I(T &x){
    x=0;char c=getchar();bool f=0;
    while(c<'0'||c>'9') {if(c=='-') f=1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    if(f) x=-x;
}

template<typename T>inline void O(T x){
    if(!x) return putchar('0'),putchar('\n'),void();
    char c[20];int t=0;
    while(x) c[++t]=(x%10)+'0',x/=10;
    while(t) putchar(c[t]),t--;
    putchar('\n');
}

#define N 2000007

namespace RTA{
    int n,far[N],sfar[N];
    LL d,x[N];
    inline void main(){
        I(n),I(d);
        for(int i=1;i<=n;i++) I(x[i]);
        LL Ans=0;
        for(int l=1,r=0;l<=n;l++){
            while(r<n && x[r+1]-x[l]<=d) r++;
            far[l]=r;
            if(r-1>l) sfar[l]=r-1;
        }
        for(int i=n;i;i--) Ans+=max(0ll,(far[i]-i)*1ll*(sfar[far[i]]-far[i]));
        O(Ans);
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    I(c),I(t);
    while(t--) RTA::main();

    return 0;
}