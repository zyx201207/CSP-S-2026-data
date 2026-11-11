#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int a[500010];
int ans;
int dc;
bool flag = false;
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    cin >> a[1];
    cin >> a[2];
    dc = a[2] - a[1];
    for(int i = 3; i <= n; i ++)
    {
        cin >> a[i];
        if(dc != a[i] - a[i - 1])
            flag = true;
    }
    sort(a + 1, a + 1 + n);
    if(flag == false)
    {
        if(dc == 0) {cout << n; return 0;}
        int k = 1;
        int s = 0;
        int an = 0;
        while(s <= m)
        {
            s += k * dc;
            k ++;
            an ++;
        }
        cout << an;
        return 0;
    }
    if(flag == true)
    {
        int p = 1;
        int k = 2;
        int cnt = 0;
        while(cnt <= m)
        {
            cnt += p * (a[k] - a[k - 1]);
            ans ++;
            k ++;
        }
        cout << ans;
        return 0;
    }
return 0;
}
