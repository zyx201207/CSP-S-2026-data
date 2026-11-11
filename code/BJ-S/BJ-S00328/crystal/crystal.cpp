#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e5 + 5;
int n, ans;
LL m, a[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    LL cost = 0;
    for(int i = 1, j = 1; i <= n; ++i){
        cost += (a[i] - a[i-1]) * (i-j);
        while(cost > m){
            cost -= a[i] - a[j];
            j++;
        }
        ans = max(ans, i-j+1);
    }
    printf("%d\n", ans);
    return 0;
}