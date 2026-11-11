#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
unsigned long long n, a, m, ans;
char c;
char x[N], y[N];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> c;
        for(int i = m; i < m + a; i++)
        {
            x[i] = c;
        }
        m += a;
    }
    for(int i = 0; i < m; i++)
    {
        if( !(x[i] == x[m] + 1 - i))
        {
            ans++;
        }
    }
    ans /= 2;
    cout << ans;
    return 0;
}
