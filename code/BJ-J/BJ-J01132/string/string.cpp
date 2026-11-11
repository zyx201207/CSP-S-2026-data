#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[200005];
string ss;
ll a[200005], cnt=0, n, m=0;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> s[i];
        m+=a[i];
        for (int j = 0; j < a[i]; j++)
        {
            ss+=s[i];
        }
    }
    ll nn=m/2;
    for (int i = 0; i < nn; i++)
    {
        if (ss[i]!=ss[m-1-i])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
