#include<bits/stdc++.h>
using namespace std;
int main()
{
long long c,t,n[300000],d[300000],x[15000][15000],a[300000],p;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);		
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n[i]>>d[i];
		p=n[i];
		for(int j=0;j<p;j++)
		{
			cin>>x[i][j];
		}
	}
	for(int i=0;i<t;i++)
	{

		for(int j=0;j<n[i];j++)
		{
			for(int l=n[i]-1;l>=j;l--)
		{
			if((x[i][l]-x[i][j])/d[i]>0&&(x[i][l]-x[i][j])%d[i]!=0)a[i]++;
		}
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<a[i]<<"\n";
	}
	return 0;
 } 
 

