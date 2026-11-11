#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000100],ans,cot[2000100],sum[2000100];
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
 	cin>>c>>t;
 	while(t--)
 	{
 		cin>>n>>d;
 		ans=0;
 		for(int i=1;i<=n;i++)
 		{
 			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				cot[j]=1e9,sum[j]=0;
			}
			cot[i]=0,sum[i]=1;
			for(int j=i;j<=n;j++)
			{
				if(sum[j]==0)
				break;
				for(int k=j+1;k<=n&&x[k]-x[j]<=d;k++)
				{
					if(cot[k]==cot[j]+1)
					sum[k]+=sum[j];
					if(cot[k]>cot[j]+1)
					{
						cot[k]=cot[j]+1;
						sum[k]=sum[j];
					}
					if(sum[k]>2)
					sum[k]=3;
				}
			}
			for(int j=i;j<=n;j++)
			ans+=(sum[j]==2);
		}
		cout<<ans<<"\n";
	}
	
 	return 0;
}
