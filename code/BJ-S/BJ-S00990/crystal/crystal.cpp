#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 7;

int n, m, a[N], b[N];
int d[N], s1[N], s2[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
 	if(n <= 5000)
	{
		int ans = 0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			int x = a[i], cnt = 0, sum = 0;
			for(int j=i;j>=1;j--)
			{
				int d = x - a[j];
				if(sum + d > m) break;
				sum += d;
				cnt ++;
			}
			ans = max(ans, cnt);
		}
		cout<<ans;
		return 0;
	}
	if(m <= 100000000)
	{
		sort(a+1, a+n+1);
		int ans = 0;
		for(int i=-100;i<=100;i++)
		{
			int pos = upper_bound(a+1, a+n+1, i) - (a+1);
			
			int sum = 0, cnt = 0;
			for(int j=pos;j>=1;j--)
			{
				int x = i-a[j];
				if(sum + x > m) break;
				
				sum += x;
				cnt ++;
			}
			ans = max(ans, cnt);
		}
		cout<<ans;
		return 0;
	}
	
	sort(a+1, a+n+1);
	int d = a[2]-a[1];
	int x = m/d;
	int sum = 0;
	for(int i=0;i<=n;i++)
	{
		if(sum + i > x)
		{
			cout<<i;
			return 0;
		}
		sum += i;
	}
	cout<<n;
	
	return 0;
}
