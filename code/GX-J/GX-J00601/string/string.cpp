#include <iostream>
using namespace std;
const int N = 2e5 + 5;
int n, l, ans, a[N];
string s, ss;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    s = "";
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> ss;
        for (int j = 1; j <= a[i]; j++)
        {
            s += ss;
        }
    }
    l = s.size();
    for (int i = 0; i <= (l + 1) / 2 - 1; i++)
    {
        if (s[i] != s[l - 1 - i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
