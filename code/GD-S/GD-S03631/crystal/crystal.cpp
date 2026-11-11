#include <bits/stdc++.h>
#define int long long
#define mid (l + r) / 2
using namespace std;

const int N = 5e5 + 5;
int n,m,a[N],sum[N];

bool cmp(int x,int y)
{
	return x > y;
}

bool check(int l,int r)
{
	int len = (r - l + 1);
	int need = (len * a[l]) - (sum[r] - sum[l - 1]);
	return need <= m;
}

int fd(int p)
{
	int l = p,r = n,res = p;
	while(l <= r)
	{
		if(check(p,mid)) res = mid,l = mid + 1;
		else r = mid - 1;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int pos = fd(i);
		ans = max(ans,pos - i + 1);
	}
	cout << ans;
	return 0;
}
