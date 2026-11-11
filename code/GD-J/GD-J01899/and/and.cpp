#include <bits/stdc++.h>
using namespace std;
long long n , m , a[200010] ,sum , num[200010] , b[200010];
void dfs(int pos)
{
	if(pos == m + 1)
	{
		long long ans = 0xfffffff;
		for(int i = 1;i <= m;i++)
			ans &= b[i];
		sum = max(ans , sum);
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(num[i])
			continue;
		b[pos] = a[i];
		num[i] = 1;
		dfs(pos++);
		num[i] = 0; 
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	dfs(1);
	cout << sum;
	return 0;
}
