//GZ-J00013 ÎÄãüºÆ
#include <bits/stdc++.h>
using namespace std;
int a[5000005],cnt[5000005];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=n; j>n-i; j++)
		{
			cin >> a[i];
			cnt[a[i]]++;
		}
	}
	return 0;
}
