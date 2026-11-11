#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	int a[100005];
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=(a[1]&a[2]);
	for(int i=1;i<=m/2;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				sum=max(sum,a[j]&a[k]);
			}
		}
	}
	cout<<sum;
	return 0;
}
