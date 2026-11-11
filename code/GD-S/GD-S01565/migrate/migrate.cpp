#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,b;
int main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int g=1;g<=t;g++)
	{
		cin>>n>>d;
		int x[n],y[n][n];
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				y[i][j]=x[j]-x[i];
			}
		}
		b=1;
		for(int i=2;i<n;i++)
		{
			if(x[i]-x[i-1]!=x[i+1]-x[i])
			{
				b=0;
			}
		}
		if(b==1)
		{
			if(n%d==0)
			{
				cout<<n/d-1<<endl;
			}
			else
			{
				cout<<n/d<<endl;
			}
		}
	}
	return 0;
}
