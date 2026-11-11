#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    long long sum = 0, ans = 0;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;
        char c;
        cin >> c;
        for (long long j = sum; j <= (sum + a); j++)
        {
            s[j] = c;
        }
        sum += a;
    }
    for (int i = 0; i <= (sum / 2) - 1; i++)
    {
        if (s[i] != s[sum - i - 1])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
