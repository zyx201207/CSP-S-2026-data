#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	vector<long long> a(n + 1);
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	long long ans = a[n];
	for(int i = n;i >= m;i--)
	{
		ans = ans & a[i];
	}
	cout << ans << endl;
	return 0;
}
