#include <bits/stdc++.h>
using namespace std;

int n, l, cnt = 0;
string s = "";

bool check(string s)
{
    for (int i = 0; i < l; i++)
        if (s[i] != s[l - i - 1])
            return false;
    return true;
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        char c;
        cin >> a >> c;
        while (a--) s += c;
    }
    l = s.size();
    if (check(s))
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < (l / 2); i++)
        if (s[i] != s[l - i - 1]) cnt++;
    cout << cnt;
    return 0;
}
