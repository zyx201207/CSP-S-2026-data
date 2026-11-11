#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n , m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int maxn = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
		maxn = max(maxn,"a[i]"&"a[j]");
		}
	}
	cout << maxn;
	return 0;
}
