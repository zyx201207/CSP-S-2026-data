#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, sum = 0, cnt = 0;
    cin >>n;
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        int a;
        char c;
        cin >> a >> c;
        sum += a;
        for (int j = 1; j <= a; j++)
        {
            s += c;
        }
    }
    for (int i = 0; i <= sum/2-1; i++)
    {
        if (s[i] != s[sum-i-1])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
