#include <bits/stdc++.h>
using namespace std;
int a[100000],ans;
string b;
int n;
int main ()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 0;i <= n;i ++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0;i <= n;i ++)
    {
        if (b[i] == b[n - i])
            continue;
        else
            ans++;
    }
    cout << ans;
    return 0;
}
