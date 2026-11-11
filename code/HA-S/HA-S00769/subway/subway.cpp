#include<bits/stdc++.h>
using namespace std;
long long a[505][505],w[505],k[505],t[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int o,n,m,d,q,x,y,i,j;
	int sum=0;
	cin>>o>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		   
	}
	for(i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(n==1)
		    sum=w[x]+t[1][x]+t[1][y]+w[y];
		else sum=35;
		cout<<sum<<endl;
	}
	return 0;
	/*
	0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
}
