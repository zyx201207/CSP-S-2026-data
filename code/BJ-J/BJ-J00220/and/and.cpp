#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[200010];
ll s[200010];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];

        if(i == 1) s[1] = a[1];
        else s[i] = s[i - 1] & a[i];
    }

    sort(a + 1,a + 1 + n);

    if(n == m)
    {
        cout << s[n] << "\n";
        return 0;
    }
    else if(m == 1)
    {
        cout << a[n] << "\n";
        return 0;
    }
    else if(a[n] < 4)
    {
        cout << a[n] << "\n";
        return 0;
    }

    ll ans = 0;

    for(ll i = 1;i <= n;i++)
    {
        ll j = i - m + 1;
        ans = max(ans,a[i] & a[j]);
    }

    cout << ans << "\n";

    fclose(stdin);
    fclose(stdout);
    return 0;
}
