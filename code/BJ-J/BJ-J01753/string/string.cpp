#include <iostream>
using namespace std;
bool isp(string x)
{
    string ans;
    for (int i = n; i > 0; i--)
    {
        ans += x[1];
    }
    return s == ans;
}
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        char a;
        cin >> x >> a;
        for (int j = 1; j <= x; j++)
        {
            s += a;
        }
    }
    if (isp(s))
    {
        cout << 0;
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i <= (s.size()- 1) / 2; i++)
        {
            if (s[i] != s[s.size()- 1 - i])
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}
