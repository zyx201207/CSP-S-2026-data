#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200010],len,sum = 0;
char b[200010];
string ans;
int main ()
{
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    cin >> n;
    for (ll i = 1;i <= n;i++)
    {
        cin >> a[i] >> b[i];
        ans += string (a[i],b[i]);
    }
    len = ans.size ();
    for (ll i = 0;i < len/2;i++)
    {
        if (ans[i] != ans[len-i-1])
        {
            sum++;
            ans[i] = ans[len-i+1];
        }
    }
    cout << sum;
    return 0;
}
