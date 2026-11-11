#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char ch[200005];
long long ans;
main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> ch[i];
    for(int l = 1,r = n; l < r; )
    {
        if(a[l] == a[r])
        {
            ans += a[l] * (ch[l] != ch[r]);
            l++;
            r--;
            continue;
        }
        if(a[l] < a[r])
        {
            ans += a[l] * (ch[l] != ch[r]);
            a[r] -= a[l];
            l++;
            continue;
        }
        ans += a[r] * (ch[l] != ch[r]);
        a[l] -= a[r];
        r--;
    }
    cout << ans;
    return 0;
}