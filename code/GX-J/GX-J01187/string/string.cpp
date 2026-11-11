#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,ans;
string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (int i  = 1; i <= n; i++)
    {
        int a;
        char c;
        cin >> a >> c;
        for (int i = 1; i <= a; i++)
            s.push_back(c);
    }
    for (int i = (int)s.size() / 2; i < s.size(); i++)
    {
        if (s[i] != s[s.size() - i - 1])
            ans++;
    }
    cout << ans;

    return 0;
}

