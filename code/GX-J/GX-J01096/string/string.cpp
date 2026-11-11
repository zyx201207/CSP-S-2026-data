#include <bits/stdc++.h>
using namespace std;
long long n,a[1000],ans=0;
char s[100];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i] >> s[i];
        if (s[i]==s[1])
        {
            ans += a[i];
        }
    }
    int h = 0;
    for (int i=1;i<=n;i++)
    {
        if (s[i]==s[1])
        {
            h++;
        }
    }
    if  (h==n)
        ans = 0;
    cout << ans;
    return 0;
}
