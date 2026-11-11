#include <bits/stdc++.h>
using namespace std;
int n,ans,l;
long long a[200005];
char c[200005];
string s;
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
        l +=a[i];
        s += c[i];
    }
    if (n==2)
    {
        if (c[0] == c[1])
        {
            cout << 0;
            return 0;
        }
        else
        {
            if (a[0] > a[1])
            {
                cout << a[1];
                return 0;
            }
            else
            {
                cout << a[0];
                return 0;
            }
        }
    }
    for (int i = 0;i <= n;i++)
    {
        if (s[i] == s[l+1-i])
            continue;
        else
            ans++;
    }
    if (l%2 == 0)
        cout << ans;
    else
        cout << ans-1;
    return 0;
}