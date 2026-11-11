#include <bits/stdc++.h>
using namespace std;
long long n, len, ans;
char ch[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        char c;
        cin >> a >> c;
        for (int j = len; j < len + a; j++)
        {
            ch[j] = c;
        }
        len += a;
    }
    for (int i = 0; i < len / 2; i++)
    {
        if (ch[i] != ch[len - i - 1])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
