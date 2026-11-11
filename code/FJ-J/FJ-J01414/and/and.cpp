#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],d[10001][10001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i][1]=a[i];
		for(int j=2;j<=i;j++)
			d[i][j]=max(d[i-1][j-1],d[i-1][j]);
	}
	cout<<d[n][m];
	return 0;
}
