#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m == 1)
	{
		sort(a+1,a+n+1);
		cout << a[n];
	}
	if(m == 2)
	{
		int cnt = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cnt = max(cnt,a[i]&a[j]);
			}
		}
		cout << cnt;
	}
	else
	{
		sort(a+1,a+n+1);
		cout << a[n-m+1];
	}
	return 0;
}
