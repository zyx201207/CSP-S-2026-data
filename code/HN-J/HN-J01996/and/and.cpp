#include <bits/stdc++.h>
using namespace std;
int n,m,a[200050];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[i]<a[j])
			{
				int b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	cout<<a[m];
	return 0;
}
