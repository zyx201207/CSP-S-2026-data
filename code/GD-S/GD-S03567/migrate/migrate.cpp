#include<bits/stdc++.h>
using namespace std;
long long num=0,n,m,x,y,a[500005],b[500005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=y;i++)
	{
		num=0;
		cin>>n>>m;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=n;j++)
		{
			b[j]=a[j]-a[j-1];
		}
		for(int k=1;k<=n;k++)
		{
			for(int j=k+1;j<=n;j++)
			{
				if((j-k)%m!=0&&b[j]<=m)
				{
					if(j-k>m)
					{ 
						int sum=(j-k)/m+(m-1);
						if(sum==2) num++;
					}
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
