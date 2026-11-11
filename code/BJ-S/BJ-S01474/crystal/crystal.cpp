#include <bits/stdc++.h>
#define int long long
using namespace std;
const int NR = 5e5 + 5;
int n, m;
int a[NR];
int s[NR];

bool check(int x)
{
    for(int i = 1; i+x-1 <= n; i++)
        if((a[i+x-1] * x) - (s[x+i-1] - s[i-1]) <= m) return true;
    return false;
}

signed main()
{
    //freopen("/home/rdfz/桌面/BJ-S01474/crystal/crystal4.in", "r", stdin);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
    int l = 1, r = n, ans = -1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid+1, ans = mid;
        else r = mid-1;
        //cout << mid << " " << check(mid) << endl;
    }
    cout << ans << endl;
    return 0;
}
