#include <bits/stdc++.h>
using namespace std;

long long n, sum, ans;
string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        long long a;
        char c;
        cin >> a >> c;
        sum = sum + a;
        for(int i = 1; i <= a; i++)
        {
            s = s + c;
        }
    }
    for(int i = 0; i <= sum / 2 - 1; i++)
    {
        if(s[i] != s[sum - i - 1])
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
