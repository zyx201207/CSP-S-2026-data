#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define TIII tuple<int,int,int>
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define il inline
#define rg register
#define fi first
#define se second
#define MAXN 500005
using namespace std;
int n,m,a[MAXN],maxn,ans,box[MAXN];
il bool cmp(int x,int y)
{
	return x > y;
}
il void solve1()
{
	sort(a+1,a+n+1,cmp);
	int ans = 0;
	for (rg int i = 1;i<=n;i++)
	{
		int sum = m;
		for (rg int j = i + 1;j<=n;j++)
		{
			if (!sum) 
			{
				ans = max(ans,j - i - 1);
				break;
			}
			else if (sum >= a[i] - a[j])
			{
				sum -= a[i] - a[j];
				if (sum == 0) 
				{
					ans = max(ans,j - i + 1);
					break;
				}
			}
			else
			{
				ans = max(ans,j - i);
				break;
			}
			if (j == n && sum) ans = max(ans,j + 1 - i);
		}
	}
	cout<<ans<<endl;
}
il void solve2()
{
	int ans = 0;
	for (rg int i = 1;i<=n;i++) 
	{
		if (a[i] <= 0) box[100 + a[i] + 1] ++;
		else box[101 + a[i]] ++;
	}
	for (rg int i = 1;i<=250;i++)
	{
		int sum = m;
		for (rg int j = i,cnt = 0;j>=1;j--)
		{
			if (!sum) 
			{
				ans = max(ans,cnt);
				break;
			}
			else if (sum >= box[j] * (i - j))
			{
				sum -= box[j] * (i - j);
				cnt += box[j];
			}
			else 
			{
				cnt += sum / (i - j);
				sum = 0;
			}
			if (j == 1) ans = max(ans,cnt);
		}
	}
	cout<<ans<<endl;
}
il void solve3()
{
	int ans = 0,r = a[2] - a[1],sum = m;
	for (rg int i = 0;i<=n;i++)
	{
		if (!sum) break;
		if (sum < i * r) sum = 0;
		else sum -= i * r,ans ++;
	}
	cout<<min(ans,n)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	bool flag1 = 1,flag2 = 1;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (rg int i = 1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	 if (m == 0)
	 {
	 	cout<<1<<endl;
	 	return 0;
	 }
	 sort(a + 1,a + n + 1);
	for (rg int i = 1;i<=n;i++)
	{
		maxn = max(maxn,abs(a[i]));
		if (a[i] != i) flag1 = 0;
		if (i >= 3 && a[i] - a[i - 1] != a[i - 1]-a[i-2]) flag2 = 0;
	 } 
	if (n <= 5000) solve1();
	else if (maxn <= 10000) solve2();
	else solve3();
	return 0;
}
