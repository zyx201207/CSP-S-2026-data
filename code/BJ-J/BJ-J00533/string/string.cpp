#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 10;

int n;
int a[N];
char s[N];
int sum;
string str;

signed main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> s[i];

        for(int j = 1; j <= a[i]; j++)
        {
            str += s[i];
        }
    }

    int ans = 0;

    int L = 0, R = str.size() - 1;

    while(L < R)
    {
        if(str[L] != str[R])
        {
            ans++;
        }

        L++, R--;
    }

    cout << ans << '\n';

    return 0;
}