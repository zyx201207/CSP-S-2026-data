#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        char c;
        cin >> a >> c;
        for (int j = 0; j < a; j++)
        {
            s += c;
        }
    }
    int sl = s.size();
    int cnt = 0;
    for (int l = 0; l < sl; l++)
    {
        int r = sl - l - 1;
        if (s[l] != s[r])
        {
            s[r] = s[l];
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
