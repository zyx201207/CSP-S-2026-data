#include<bits/stdc++.h>
using namespace std;
int x[1000000]={0};
int p[1000000]={0};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,d,sum=0;
		cin>>n>>d;
		for(int j=1;j<=n+5;j++)
		{
			x[j]=0;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		for(int k=1;k<=n-1;k++)
		{
			int u=0;
			for(int j=1;j<=n;j++)
			{
				if(x[j]>x[1]+d)
				{
					u=j-1;
				}
			}
			int s=0;
			for(int j=1;j<=d;j++)
			{
				for(int z=1;z<=u;z++)
				{
					p[k*10+z]=x[z]+j;
					if(p[k*10+z]==x[n])
					{
						s+=1;
					}
				}
			}
			if(s==2)
			{
				sum+=1;
			}
		}
		if(sum>=2)
		{
			sum-=2;
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
