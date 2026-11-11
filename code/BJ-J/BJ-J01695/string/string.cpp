#include <iostream>
using namespace std;

int n;
string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int ai;
        char ci;
        cin >> ai >> ci;
        for (int i = 1; i <= ai; i++)
        {
            s += ci;
        }
    }

    int len = s.size();
    int ans = 0;

    if (len % 2 == 1)
    {
        for (int i = 0; i < len / 2; i++)
        {
            if (s[i] != s[len - i - 1]) ans++;
        }
    }
    else
    {
        for (int i = 0; i < len / 2; i++)
        {
            if (s[i] != s[len - i - 1]) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
