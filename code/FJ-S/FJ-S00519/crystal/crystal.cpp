#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
ll n, m;
ll a[N], cost, p, ans, h = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld", &n, &m);
    for(int i = 1;i <= n;++i)scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;++i){
        if(p)cost += p * (a[i] - a[i - 1]);
        while(h < i && cost > m)cost -= (a[i] - a[h]), ++ h, --p;
        ++p;
        ans = max(ans, p);
    }
    printf("%lld", ans);
    return 0;
}