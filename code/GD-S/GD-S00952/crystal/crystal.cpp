#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;

const int N = 5e5 + 5;
int a[N],pre[N];

bool check(int x)
{
	int ans = 1e18;
	for(int i = x;i <= n;i++)
	{
		int sum = pre[i] - pre[i - x];
		ans = min(x * a[i] - sum,ans);
	}
	return ans <= m;
}

signed main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
	int l = 1,r = n,ans = 0;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(check(mid)) 
		{
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
