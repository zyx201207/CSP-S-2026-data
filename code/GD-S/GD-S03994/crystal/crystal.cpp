#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;

int n;
long long m,a[N],c[N],ans;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool ok = true;
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	sort(a+1, a+n+1);
	
	for(int i = 1; i < n; i++)
	{
		c[i] = a[i+1] - a[i];
	}
	c[n] = 0;
	
	for(int i = 1; i < n-1; i++)
	{
		if(c[i] != c[i+1])	ok = false;
	}
	
	if(ok)
	{
		ans = 1;
		while(1)
		{
			m -= ans*c[1];
			if(m < 0)	break;
			ans++;
		}
		cout << ans << '\n';
		return 0;
	}
	
	for(int i = 1; i < n; i++)
	{
		long long sum = c[i],k = 1;
		for(int j = i+1; j <= n; j++)
		{
			if(sum > m)	
			{
				break;
			}
			k++;
			sum += k*c[j];
		}
		ans = max(ans,k);
	}
	
	
	cout << ans <<'\n';
	return 0;
 } 
