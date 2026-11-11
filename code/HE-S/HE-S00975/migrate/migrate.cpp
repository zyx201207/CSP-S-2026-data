#include<bits/stdc++.h>
using namespace std;
int n[200006];
int d[200006];
int x[200006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int b=0;
	int c,t;
	cin>>c>>t;
	int j=0;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		int c=d[i];
		for( j=1;j<=n[i];j++)
		{
			cin>>x[j];
			if(d[i]>=x[j])
			{
				if(d[i]<x[j]+x[j+1])
				{
					
				}
			}
		}
		if(d[i]==x[j])
		{
			for(int j=x[j-1];j>=1;j--)
			{
				b+= d[j];
			}
			cout<<b;
			b=0;
		}
	}
	

}
