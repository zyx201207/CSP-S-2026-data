#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef long long ll;
const int N = 1e8 + 5;
ll n, x, ans, idx;
char y, s[N];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        for (int j = 1; j <= x; j++)
            s[++idx] = y;
    }
    ll l = 1, r = idx;
    while (l < r)
    {
        if (s[l] != s[r])
            ans++;
        l++;
        r--;
    }
    cout << ans << "\n";
    return 0;
}
