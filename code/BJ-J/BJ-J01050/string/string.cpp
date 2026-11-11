#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+8;
int n, a[N], cnt;
char s[N];

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i] >> s[i];
    int l = 1, r = n;
    while(l<r)
    {
        int mi = min(a[l], a[r]);
        if (s[l]!=s[r])cnt += mi;
        a[l] -= mi;
        a[r] -= mi;
        if (a[l]==0)l++;
        if (a[r]==0)r--;
    }
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
