#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long l,r,ans;
char t[200005];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    r = 0;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i] >> t[i];
        r += a[i];
        for (int j= 1;j <= a[i];j++)
        {
            s+=t[i];
    	}
        cout << s;
    }
    l = 0;
    ans = 0;
    while (l <= r/2)
    {
        if (s[l] != s[r])
        {
            ans ++;
        }
        l++;
        r--;
    }
    cout << ans;
    return 0;
}
