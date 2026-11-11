#include <iostream>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    string s = "";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        char y;
        cin >> x >> y;
        for (int i = 1; i <= x; i++)
        {
            s += y;
        }
    }
    n = s.size();
    if (n % 2 == 1)
    {
        int ans = 0;
        for (int i = 1; i <= n / 2; i++)
        {
            if (s[i - 1] != s[n - i])
            {
                ans++;
            }
        }
        cout << ans;
    }
    else if (n % 2 == 0)
    {
        int ans = 0;
        for (int i = 1; i <= n / 2; i++)
        {
            if (s[i - 1] != s[n - i])
            {
                ans++;
            }
        }
        cout << ans;
    }
    return 0;
}
