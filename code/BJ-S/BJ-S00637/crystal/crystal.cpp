#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,last;
int a[500005];
bool check(int tmp)
{
    int sum = 0;
    for(int i=1; i<tmp; i++)
    {
        sum += (a[tmp]-a[i]);
    }
    return (sum <= m);
}
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    int l=1, r=n;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(check(mid) == 1)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid -1;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
