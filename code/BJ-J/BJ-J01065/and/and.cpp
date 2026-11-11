#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;

int n, m, a[N];
int pre[N], nxt[N];

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(m == 1)
	{
		sort(a+1, a+n+1);
		cout<<a[n];
		return 0;
	}
	
	if(m == 2)
	{
		int ans = 0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans = max(ans, (a[i] & a[j]) );
		cout<<ans;
		return 0;
	}
	
	if(m == n-1)
	{
		pre[0] = (1 << 30) - 1;
		for(int i=1;i<=n;i++) pre[i] = pre[i-1] & a[i];
		
		nxt[n+1] = (1 << 30) - 1;
		for(int i=n;i>=1;i--) nxt[i] = nxt[i+1] & a[i];
		
		int ans = 0;
		for(int i=1;i<=n;i++)
		{
			int x = (pre[i-1] & nxt[i+1]);
			ans = max(ans, x);
		}
		cout<<ans;
		return 0;
	}
	
	if(m == n)
	{
		int ans = (1 << 30) -1;
		for(int i=1;i<=n;i++)
		{
			ans &= a[i];
		}
		cout<<ans;
		return 0;
	}
	
	sort(a+1, a+n+1);
	int ans = (1 << 30) -1;
	for(int i=n;i+m-1>=n;i--)
	{
		ans &= a[i];
	}
	cout<<ans;
	
	return 0;
}
