#include<bits/stdc++.h> 
using namespace std;
long long c,t,n,d;
long long x[2000005];
long long f[2000005];
long long minn;
long long ans;
void find(int now,int end,int step)
{
	if(now==end)
	{
		if(step<minn)
		{
			minn=step;
			ans=1;
		}
		else if(step==minn) ans++;
	}
	for(long long i=now+1;i<=end;i++)
	{
		if(x[i]-x[now]<=d) find(i,end,step+1);
		else break;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				minn=1e9;
				ans=0;
				find(i,j,0);
				if(ans==2)
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
