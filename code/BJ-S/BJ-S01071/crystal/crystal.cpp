#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int NR = 5e5 + 10;
ll a[NR];
ll s[NR];
//ll pre[NR];
int n;
ll m;

int fans(int x) {
    ll t = a[x];
    int l = 1, r = x;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(t * (x - mid + 1) - (s[x] - s[mid - 1]) <= m) {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return x - (r + 1) + 1;
}

//int stk[NR], tt;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        //s[i] = a[i] + s[i - 1];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
        s[i] = a[i] + s[i - 1];
    }
    /*
    for(int i = 1; i <= n; i++) {
        while(tt && a[stk[tt]] <= a[i]) tt--;
        pre[i] = stk[tt];
        stk[++tt] = i;
    }
    */
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int sum = fans(i);
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}
