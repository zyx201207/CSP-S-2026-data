#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];	
	}	
	int k[n+1];
	int a[2*n+1][2*n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++)
		{
			cin>>a[i][j];
		}
	}
	int x[q+1];
	int y[q+1];
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	return 0;
} 
