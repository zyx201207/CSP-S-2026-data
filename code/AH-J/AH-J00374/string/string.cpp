#include <bits/stdc++.h>
using namespace std;
long long n, sum, cnt;
string s;
long long x;
char y;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        sum += x;
        for(int j = 1; j <= x; j++)
        {
            s = s + y;
        }
    }
    for (int i = 0; i <= sum / 2 - 1; i++)
    {
        if(s[i] != s[sum - i - 1])
        {
            cnt++;
        }
        else
        {
            continue;
        }
    }
    cout << cnt;
    return 0;
}
