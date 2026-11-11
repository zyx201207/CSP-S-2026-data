#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
long long v[2000005];
long long dis[2000005];
long long z[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(long long i=1;i<=t;i++)
	{
		long long n,d;
		cin>>n>>d;
		for(long long j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		long long ans=0;
		for(long long j=1;j<=n;j++)
		{
			memset(v,0,sizeof(v));
			memset(dis,0,sizeof(dis));
			memset(z,0,sizeof(z));
			queue<long long> q;
			q.push(j);
			v[j]=true;
			dis[j]=0;
			while(!q.empty())
			{
				long long cnt=q.front();
				q.pop();
				for(long long k=1;k<=n;k++)
				{
					if(abs(a[k]-a[cnt])<=d&&v[k]==0)
					{
						q.push(k);
						v[k]=1;
						dis[k]=dis[cnt]+1;
						z[k]++;
					}
					else
					{
						if(abs(a[k]-a[cnt])<=d&&v[k]==1&&dis[k]==dis[cnt]+1)
						{
							z[k]++; 
							if(z[k]==2)
							{
								
							}
						}
					}
				}
			}
			for(long long k=1;k<=n;k++)
			{
				if(z[k]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans/2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
