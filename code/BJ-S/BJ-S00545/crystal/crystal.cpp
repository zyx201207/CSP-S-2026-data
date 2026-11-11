#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N = 5e5 + 5;
int a[N];
int ans = 0;
int st;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    int total = a[1];
    int cha = 0;
    int now;
    ans = 1;
    st = 1;
    for(int i = 2;i <= n;i++)
    {
        now = a[i];
        cha = (i - st) * now - total;
        while(m < cha && st < i)
        {
            total -= a[st];
            st++;
            cha = (i - st) * now - total;
        }
        total += a[i];
        ans = max(ans,i - st + 1);
    }
    cout << ans << '\n';
    return 0;
}
