#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f,cnt;
int main()
{
	cin >> n>> m;
	for(int i=1;i<=n;i++)
	{
		cin>> a[i];
		if(f==a[i])
		{
			cnt++;
		}
		f=a[i];
	}
	if(cnt==n-1)
	{
		cout << n;
		return 0;
	}
	for(int k=1;k<=n;n++)
	{
		for(int i=n;i>=k;i--)
		{
			int sum=0;
			for(int j=1;j<i;j++)
			{
				sum+=a[i]-a[j];
			}
			if(sum<=m)
			{
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}
