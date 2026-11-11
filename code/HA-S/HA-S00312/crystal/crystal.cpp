#include <bits/stdc++.h>
using namespace std;
long long n,m,a[50005],num;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mid=n/2+1;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (a[mid]-a[i]+a[mid]-a[j]==m)
			{
				num=3;
				break;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]==a[mid]&&i!=mid)
		{
			num++;
		}
	}
	cout<<num;
	return 0;
}
