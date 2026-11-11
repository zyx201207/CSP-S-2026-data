#include<bits/stdc++.h>
using namespace std;
int n, m, a[20005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int maxn = 0;
	for(int i = 1; i <= n; i++)
	{
		int sum = a[i];
		for(int j = 2; j <= m; j++)
		{
			sum = sum & a[i+j-1];
		}
		maxn = max(maxn,sum);
	}
	cout << maxn;
	return 0;
 } 
