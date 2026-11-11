#include <bits/stdc++.h>
using namespace std;

string s;
string ch[202020];
long long n,a[202020],c,ans;

int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> ch[i];
        for (int j = 1; j <= a[i]; ++j)
        {
            s += ch[i];
        }
    }
    c = s.size();
    /*
    for (int i = 0; i <= c - 1; ++i)
    {
        cout << s[i];
    }
    cout << endl;
    */
    if (c % 2 == 1)
    {
        for (int i = 0; i <= c / 2; ++i)
        {
            if (s[i] != s[c - i - 1])
            {
                ans++;
            }
            //cout << i << " " << c - i - 1 << endl;
        }
    }
    else
    {
        for (int i = 0; i <= c / 2 - 1; ++i)
        {
            if (s[i] != s[c - i - 1])
            {
                ans++;
            }
            //cout << i << " " << c - i - 1 << " " << (s[i] == s[c - i - 1]) << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
