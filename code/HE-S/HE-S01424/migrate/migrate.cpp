#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int n,d,p=0;
	cin>>c>>t;
	cin>>n>>d;
	int k[n][t],k1[n+1][n+1];
	for(int i=0;i<t;i++)
		for(int j=0;j<n;j++)
			cin>>k[j][t];
	for(int i=0;i<t;i++)
	{
		p=0;
		for(int j=0;j<n;j++)
		{
			for(int h=0;h<n;h++)
			{
				k1[j][h]=k[h][t]-k[j][t];
			}
		}
		for(int j=0;j<n;j++)
		{	
			for(int j1=j+1;j1<n;j1++)
			{
				for(int h=0;h<n;h++)
				{
					if(k1[j][h]==k1[j1][h] && k1[j][h]<d)
						p++;
				}		
			}
		}
		cout<<p;
		if(i==0)
			cout<<endl;
	}
	return 0;
} 
