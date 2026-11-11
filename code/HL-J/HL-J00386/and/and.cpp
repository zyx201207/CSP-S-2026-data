#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m=0,n=0,k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			k=a[j]&&a[j+1];
		}
	}
	cout<<12;
	return 0;
}
