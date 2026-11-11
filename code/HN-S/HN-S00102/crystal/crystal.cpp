#include <bits/stdc++.h>
using namespace std;

int n;
long long m,sum[500005],a[500005];
bool check(int x,int st)
{
	long long ne = sum[st] - sum[st - x];
	if(x * a[st] - ne <= m) return true;
	return false;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int l = 0,r = i + 1;
		while(l + 1 < r)
		{
			int mid = (l + r) / 2;
			if(check(mid,i)) l = mid;
			else r = mid;
		}
		ans = max(ans,l);
//		cout << l << '\n';
	}
	cout << ans;
	return 0;
}
