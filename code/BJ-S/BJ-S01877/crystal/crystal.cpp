#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 5e5;
int a[N + 5];
int n,m;
int p,s,sz;

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
    sort(a + 1,a + 1 + n);
    int ans = 1;
    sz = 1;
    p = 1;
    int res = 1;
    for(int i = 2;i <= n;i++)
    {
        ans++;
        s += sz * (a[i] - a[i - 1]);
        sz++;
        while(p <= i && s > m)
        {
            s -= a[i] - a[p];
            p++;
            sz--;
            ans--;
        }
        //cout << p << ' ' << sz << ' ' << s << ' ' << ans <<endl;
        res = max(res,ans);
    }
    cout << res;
	return 0;
}
