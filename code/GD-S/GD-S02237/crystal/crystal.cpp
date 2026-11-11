#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+55;
int a[N];
int n,m;
int sum[N];
bool check(int x)
{
	int ans1 = LLONG_MAX;
	for(int i = x;i<=n;i++)
	{
		ans1 = min(ans1,x * a[i] - (sum[i] - sum[i-x]));
	}
	if(ans1 <= m)
	{
		return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i<=n;i++)
	{
		sum[i] = sum[i-1] + a[i];
	}
	int l = 1,r = n+1;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(check(mid))
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	cout<<l - 1<<endl;
	return 0;
 } 
