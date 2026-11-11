#include <bits/stdc++.h>
using namespace std;
#define int long long

const int NR = 5e5 + 5;
int n, m;
int a[NR], d[NR];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i ++){
        d[i] = a[i] - a[i-1];
    }
    int ans = 0;
    for(int i = 1, j = 1, sum = 0, len = 1; i <= n; i ++){
        while(j+1 <= n && sum + len*d[j+1] <= m) sum += len*d[j+1], len ++, j ++;
        //cout << i << ' ' << j << ' ' << sum << '\n';
        ans = max(ans, len);
        sum -= (a[j]-a[i]);
        len --;
    }
    cout << ans << endl;
    return 0;
}
/**

5 8
-3 -1 2 2 7

**/
