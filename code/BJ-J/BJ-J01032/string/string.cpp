#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string s;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n, cnt = 1, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char c;
        cin >> a[i] >> c;
        s += c;
    }
    if(n % 2 == 0)
    {
        for(int i = 1; i <= n / 2; i++)
        {
            if(s[i - 1] != s[n - i])
            {
                ans += min(a[i], a[n + 1 - i]);
                if(a[i] != a[n + 1 - i])
                {
                    ans += abs(a[i] - a[n + 1 - i]);
                    if(a[i] >= a[n + 1 - i])
                        a[n - i] = a[n - i] - abs(a[i] - a[n + 1 - i]);
                    else
                        a[i + 1] = a[i + 1] - abs(a[i] - a[n + 1 - i]);
                }
            }
        }
    }
    else
    {
        for(int i = 1; i <= n / 2 + 1; i++)
        {
            if(s[i - 1] != s[n - i])
            {
                ans += min(a[i], a[n + 1 - i]);
                if(a[i] != a[n + 1 - i])
                {
                    ans += abs(a[i] - a[n + 1 - i]);
                    if(a[i] >= a[n + 1 - i])
                        a[n - i] = a[n - i] - abs(a[i] - a[n + 1 - i]);
                    else
                        a[i + 1] = a[i + 1] - abs(a[i] - a[n + 1 - i]);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
