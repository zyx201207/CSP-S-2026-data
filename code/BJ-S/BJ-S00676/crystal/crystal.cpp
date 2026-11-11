#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e5 + 5;
int n;
ll m;
ll a[MAXN];

int main(){
    #ifndef kevin
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    #endif
    scanf("%d%lld",&n,&m);
    for (int i = 1;i <= n;i ++)scanf("%lld",a + i);
    sort(a + 1,a + n + 1);
    ll cost = 0;
    int j = 1;
    int ans = 0;
    for (int i = 1;i <= n;i ++){
        while (cost > m){
            ll v = a[i] - a[j];
            cost -= v;
            j ++;
        }
        ans = max(ans,i - j + 1);
        cost += (i - j + 1) * (a[i + 1] - a[i]);
    }
    printf("%d\n",ans);
    return 0;
}