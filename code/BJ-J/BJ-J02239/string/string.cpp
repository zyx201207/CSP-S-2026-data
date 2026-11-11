#include <bits/stdc++.h>
using namespace std;
int a[200005];
char s[20005];
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);


    long long n,ans=0;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i] >> s[i];
    }
    if (n%2==0)
    {
        for (int i=1;i<=n/2;i++)
        {
            if (s[i]!=s[n-i+1])
            {
                ans+=min(a[i],a[n-i+1]);
            }
        }
    }
    else
    {
        for (int i=1;i<=n;i++)
        {
            if (s[i]!=s[n-i+1])
            {
                ans+=min(a[i],a[n-i+1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
