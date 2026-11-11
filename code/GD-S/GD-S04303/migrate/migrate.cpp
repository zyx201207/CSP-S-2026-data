#include<bits/stdc++.h>
using namespace std;
int a[2000001];
int dp[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(int y=1;y<=t;y++)
	{
		long long n,k,tou=1,sum=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n-1;i++)
		{
			if(a[i+1]-a[i]>k)
			{
				n=i;
				break;
			}
		}
		for(int x=2;x<=n;x++)
		{
				int biao;
		for(int i=x;i<=n;i++)
		{
			int biao=0;
			for(int f=i-1;f>=x-1;f--)
			{
				if(a[i]-a[f]<=k)
				{
					biao=f;
				}
				else{
					break;
				}
			}
			int minn=dp[biao];
			for(int f=biao+1;f<i;f++)
			{
				if(minn>dp[f])
				{
					minn=dp[f];
				}
			}
			dp[i]=minn+1;
			int shu=0;
			for(int f=biao;f<i;f++)
			{
				if(minn==dp[f])
				{
					shu++;
				}
			}
			if(shu==2)
			{
				sum++;
			}
		}
		
		}
		cout<<sum<<endl;
		
	}
	return 0;
}
