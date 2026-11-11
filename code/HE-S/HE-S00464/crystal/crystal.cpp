#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[259760];
	cin >> n >> m;
	
	for(int i = 1; i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans = 1;
	long long k = m;
	for(int i = 1;i <= n;i++)
	{
		int aans = 1;
		for(int j = i-1;j >= 0&&k >= 0;j--)
		{
			if((k-(a[i]-a[j]))>=0)
			{
				k-=(a[i]-a[j]);
				aans++;
			}
		}
		ans = max(ans,aans);
	}
	cout << ans;
	return 0;
}


