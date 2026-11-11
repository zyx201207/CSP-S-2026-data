#include <bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10001];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int maxn=-1;
	for(int i=1;i<=n-m+1;i++)
	{
		int c;
		for(int j=2;j<=m;j++)
		{
			c=a[i]&a[i+j];
		}
		if(c>maxn)
		{
			maxn=c;
		}
	}
	cout<<maxn<<endl;
	return 0;
}
