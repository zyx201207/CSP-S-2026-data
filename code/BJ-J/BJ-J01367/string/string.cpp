#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n, ai, sum = 0;
    string s = "", t = "";
    char ci;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> ai >> ci;
        for (long long j = 1; j <= ai; j++)
        {
            s += ci;
        }
    }
    for (long long i = s.size() - 1; i >= 0; i--)
    {
        t += s[i];
    }
    for (long long i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
        {
            sum++;
        }
    }
    cout << sum / 2;
    return 0;
}
