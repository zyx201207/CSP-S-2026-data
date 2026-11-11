#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node
{
    int len;
    char c;
}inputs[N];
string s;
int dp[20005][20005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> inputs[i].len >> inputs[i].c;
    }int base = __gcd(inputs[1].len,inputs[2].len);
    for (int i = 2;i <= n;i++)
    {
        base = __gcd(inputs[i].len,inputs[i + 1].len);
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= inputs[i].len / base;j++) s = s + inputs[i].c;
    }s = " " + s;
    for (int i = 1;i <= s.length() - 1;i++)
    {
        for (int j = 1;j <= s.length() - i;j++)
        {
            if (s[j] == s[j + i - 1]) dp[j][j + i - 1] = dp[j + 1][j + i - 2];
            else dp[j][j + i - 1] = dp[j + 1][j + i - 2] + 1;
        }
    }
    cout << 1LL * dp[1][s.length() - 1] * base;
}
