#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 10;
int n,m,a[maxn];
bool vis[maxn];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	int l = 1,r = 1; int now = 0,mx = 1;
	vis[1] = 1;
	while(r <= n)
	{
		if(r <= n) r++,vis[r] = 1;
		int len = r-l+1;
		now += len * 1ll*(a[r]-a[r-1]);
		if(now > m)
		{
			now -= 1ll*(a[r] - a[l]);
			l++; vis[l] = 0;
		}
		if(now <= m) mx = max(mx,len);
	}
	cout << mx;
	return 0;
}

