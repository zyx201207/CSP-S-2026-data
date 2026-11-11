#include <bits/stdc++.h>
using namespace std;

int n;
string s;
long long ans;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
    {
        int t;
        char c;
        cin >> t >> c;
        while (t--)
        {
            s += c;
        }
    }
    string s1 = s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s1[i] != s[i])
        {
            ans++;
        }
    }
    cout << ans / 2;
    return 0;
}
