#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 2e5 + 10;
LL n,m,x[N];
struct Node{
    LL d;
    string s;
}a[N];
string transf_2(LL n){
    string s;
    while(n){
        s += n % 2;
        n /= 2;
    }
    reverse(s.begin(),s.end());
    return s;
}
bool cmp(const Node &x,const Node &y){
    if(x.s.size() != y.s.size()) return x.s.size() > y.s.size();
    return x.s > y.s;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i = 1;i <= n;i++) scanf("%lld",&x[i]);
    if(m == 1){
        LL maxn = 0;
        for(LL i = 1;i <= n;i++) maxn = max(maxn,x[i]);
        printf("%lld",maxn);
    }else if(m == 2){
        LL maxn = 0;
        for(LL i = 1;i <= n;i++){
            for(LL j = i + 1;j <= n;j++) maxn = max(maxn,x[i] & x[j]);
        }
        printf("%lld",maxn);
    }else if(n == m){
        LL ans = 0;
        for(LL i = 1;i <= n;i++) ans &= x[i];
        printf("%lld",ans);
    }else{
        for(LL i = 1;i <= n;i++){
            a[i].s = transf_2(x[i]);
            a[i].d = x[i];
        }
        sort(a + 1,a + n + 1,cmp);
        LL ans = a[1].d;
        for(LL i = 2;i <= m;i++) ans &= a[i].d;
        printf("%lld\n",ans);
    }
    return 0;
}
