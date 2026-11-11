#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N] , sa[N];
int n , m;
bool check(int x , int i)
{
    return (sa[i] - sa[x - 1] - (i - x + 1) * (a[n] - a[i])) <= m;
}
int find(int ed)
{
    int l = 1 , r = ed;
    int ans = 1;
    while (l <= r)
    {
        // cout << l << " " << r << endl;
        int mid = (l + r + 1) / 2;
        // if (a[mid] >= tar)
        if (check(mid , ed))
        {
            r = mid - 1;
            ans = mid;
            // cout << mid << " " << ed << endl;
        }
        else
        {
            l = mid + 1;
        }
    }
    // cout << l << " " << ed << endl;
    // cout << ans << " " << ed << endl;
    // cout << endl;
    return ans;
    // cout << l << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    for (int i = 1 ; i <= n ; i++)
    {
        sa[i] = sa[i - 1] + a[n] - a[i];
        // cout << sa[i] << " ";
    }
    // cout << endl;
    int ans = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        ans = max(ans , i - find(i) + 1);
    }
    cout << ans << endl;
    return 0;
}
/*
5 5
1 2 4 8 9

1 3 7 15 16

8 7 5 1 0
8 15 20 21 21


*/