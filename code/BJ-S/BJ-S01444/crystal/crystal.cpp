#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0, sum = 0;
    for (int i = 1, j = 1; j <= n; j ++)
    {
        int tmp = a[j] * (j - i) - sum;
        while (i < j && tmp > m)
        {
            sum -= a[i ++];
            tmp = a[j] * (j - i) - sum;
        }
        sum += a[j];
        ans = max(ans, j - i + 1);
    }
    cout << ans;

    return 0;
}