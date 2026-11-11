#include <bits/stdc++.h>
typedef long long LL;

LL ru(){
    LL r=0,c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){
        r=r*10+c-'0';
        c=getchar();
    }
    return r;
}

namespace solve{
    const LL MAX_N=5e5+1000;
    LL N,M,A[MAX_N];
    struct dist{
        LL w=0,L=1,R=0;//s=size
        void pop(){
            w-=A[R]-A[L];
            L++;
        }
        LL add(){
            LL i=R+1;
            w+=(R-L+1)*(A[i]-A[i-1]);
            R++;
            while(w>M){pop();}
            return (R-L+1);
        }
    }DI;
    void solve(){
        LL ans=0;
        scanf("%lld%lld",&N,&M);
        for(int i=1;i<=N;i++)scanf("%lld",&A[i]);
        std::sort(A+1,A+1+N);
        for(int i=1;i<=N;i++){
            ans=std::max(ans,DI.add());
        }
        std::cout<<ans;
    }
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    solve::solve();
    return 0;
}
