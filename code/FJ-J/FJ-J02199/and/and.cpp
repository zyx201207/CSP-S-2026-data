#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin >> n >> m; 
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int maxn=-1,sum=2147483647;
	for (int i = 1;i <= n-m+1;i++)
	{
		sum=2147483647;
		maxn=-1;
		for (int j = i;j <= i+m-1;j++)
		{
			sum = sum & a[j];
		}
		if (sum > maxn) maxn = sum;
	}
	cout << maxn;
	return 0;
} 
