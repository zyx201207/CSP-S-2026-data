#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int b=0;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			b=max(b,a[i]);
		}
		cout<<b;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<=m;j++)
		{
			int c=1;
			c=a[i]&a[j];
			b=max(b,c);
		}
	}
	cout<<b;
	return 0;
}
