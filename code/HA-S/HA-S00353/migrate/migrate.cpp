#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,x[2000005];
int lj[2000005],s=0,ans[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
			cin>>x[j];
		for(int j=0;j<(1<<n);j++)
		{
			for(int k=0;k<n;k++)
			{
				if(j&(1<<k))
				{
					if(x[k]-x[s]<=d)
					{
						lj[j]+=x[k]-x[s];
						s=k;
					}
					else
						break;
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(lj[i]==lj[j]&&i!=j)
			{
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
