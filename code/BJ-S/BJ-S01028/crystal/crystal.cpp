#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define N 500007

namespace RTA{
    int n;
    LL m,a[N],s[N];
    inline int getseg(int r){
        int L=1,R=r;
        while(L<R){
            int mid=(L+R)>>1;
            int len=r-mid+1;
            if(a[r]*len-(s[r]-s[mid-1])<=m) R=mid;
            else L=mid+1;
        }
        return r-L+1;
    }
    inline void main(){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        int Ans=1;
        for(int i=2;i<=n;i++) Ans=max(Ans,getseg(i));
        cout<<Ans<<'\n';
    }
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    RTA::main();

    return 0;
}
//g++ crystal.cpp -o crystal
//./crystal