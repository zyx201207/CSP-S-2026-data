#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+500;
long long a[N]={},f[N]={},ans = 0;
long long n,m;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	cin >> a[i];
	sort(a+1,a+n+1);	
	long long mid = (n+1)/2,k = 1;
	for (int i = 1;i <= n;i++)
	{
		f[k] = abs(a[mid]-a[i]); k++;
	}
	k--;
	sort(f+1,f+k+1);
	for (int i = 1;i <= k;i++)
	{
		if (m - f[i] >= 0)
		{
			ans += 1;
			m -= f[i];
		}
	}
	cout << ans;
	return 0;
}
