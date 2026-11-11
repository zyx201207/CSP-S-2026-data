#include<bits/stdc++.h>
using namespace std;
int n, l, ans;
long long m, a[500005], s[500005];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++){
        s[i] = (long long)s[i - 1] + a[i];
        while(a[i] * ((long long)i - l) - s[i] + s[l] > m) l++;
        ans = max(ans, i - l);
    }
    printf("%d", ans);
    return 0;
}
