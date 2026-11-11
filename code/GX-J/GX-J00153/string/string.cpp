#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    long long cnt = 0;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long m;
        char c;
        cin >> m >> c;
        for (int j = 1; j <= m; j++)
        {
            s += c;
        }
    }
    string s1 = s;

    reverse(s.begin(), s.end());

    cout << s1 << endl;
    cout << s << endl;

    for (int i = 0; i < s.size() / 2; i++)
    {
       if (s[i] != s1[i])
       {
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
