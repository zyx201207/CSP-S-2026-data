#include<bits/stdc++.h>
#include<stack>
using namespace std;
int c,t,n,h[5005],sum,cnt,num,v,s,k;
stack<int> p;
long long x[5005],d,f[5005][5005];
int main()
{
	cin>>c>>t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(int s=1;s<=t;s++)
	{
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			h[i]=n;
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					f[i][j]=1;
				}
				else
				{
					h[i]=j-1;
					break;
				}
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				s=(x[j]-x[i]+d-1)/d;
				if(f[i][j]!=1)
				{
					p.push(x[i]);
					while(!x[j]-p.top()<=d)
					{
						for(int l=i+1;l<=n;l++)
						{
							if(x[j]-x[l]<=(s-1)*d)
							{
								
							}
						}
					}
				}
			}
		}
	}
	return 0; 
}
