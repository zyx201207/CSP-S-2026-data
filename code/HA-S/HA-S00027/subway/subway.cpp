#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000],a[1000][1000],t[1000][1000],k[1000],x[1000],y[1000],i,j,r;
int main()
{
	freopen("subyay","r",stdin);
	freopen("subyay","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=m;i++)
	{
		cin>>w[m];
	}
	for(int i=0;i<=n;i++)
	{
		cin>>k[i];
		for(int j=0;i<=n;j++)
		{
			cin>>a[i][j]>>t[i][j];
			
		}
	}
	for(int i=0;i<=i;i++)
	{
		cin>>x[r]>>y[r];
	}
	sort(a,a+1);
	int sum;
	for(int i=0;i<=n;i++)
	{	
		sum+=w[i]+t[i][j]+t[i+1][j]+w[i+1];
	}
	cout<<sum;
}
