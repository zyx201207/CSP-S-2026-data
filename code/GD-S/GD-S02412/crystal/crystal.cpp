#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++)
		s[i] = a[i] + s[i-1];
	long long ans = 0;
	for(long long i = 1;i <= n;i++)
	{
		long long num = s[i]+m;
		num = num/a[i];
		num = min(i,num);
		ans = max(num,ans);
	}
	cout << ans;
	return 0;
}
