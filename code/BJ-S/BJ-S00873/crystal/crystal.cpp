#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N = 5e5 + 5;

int n,m,a[N],s[N];

int calc(int l,int r)
{
    return (r - l) * a[r] - s[r-1] + s[l-1];
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
    int res = 0;
    for(int i=1;i<=n;i++)
    {
        int l = 1, r = i - 1, ans = 1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(calc(mid,i) <= m) r = mid - 1, ans = i - mid + 1;
            else l = mid + 1;
        }
        // cout << ans << '\n';
        res = max(res,ans);
    }
    cout << res << '\n';
    return 0;
}