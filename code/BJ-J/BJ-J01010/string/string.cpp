#include <bits/stdc++.h>
using namespace std;
const long long N = 1e8 + 5;
int n;
long long sum, l;
char s[N];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1, a; i <= n; ++i)
    {
        char t;
        cin >> a >> t;
        for (int j = 1; j <= a; ++j)
        {
            s[j + sum - 1] = t;
        }
        sum += a;
    }
    l = sum;
    for (int i = 0; i < l / 2; ++i)
    {
        if (s[i] == s[l - i - 1])
        {
            sum -= 2;
        }
    }
    cout << sum / 2;
    return 0;
}