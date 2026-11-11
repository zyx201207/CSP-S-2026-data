#include<bits/stdc++.h>
using namespace std;
long long n,m,a[11415400],ans[1145410],maxn = -1e9;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	} 
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			ans[i] = a[i] & a[j]; 
		}
	}
	for(int i = 1;i <= n;i++)
	{
		maxn = max(ans[i],maxn);
	}
	cout << maxn;
	return 0;
} 
