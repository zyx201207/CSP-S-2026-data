#include <bits/stdc++.h>
using namespace std;
int n;
long long a,ans,sum;
char c;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a >> c;
        for (int j = 1;j <= a;j++)
        {
            s += c;
            sum++;
        }
    }
    long long l = 0,r = sum - 1;
    while (l <= r)
    {
        if (s[l] != s[r])
        {
            ans++;
        }
        l++;
        r--;
    }
    cout << ans;
    return 0;
}
