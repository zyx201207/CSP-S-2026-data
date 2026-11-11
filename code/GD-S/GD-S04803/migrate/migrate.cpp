#include<iostream>
using namespace std;
int a[2000005];
int dp[2000005];
int sum[2000005];
int b[2000005];
int n,d;
bool check(int p,int cv)
{
	return p>=cv-d;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			dp[i]=0;
			sum[i]=0;
		}
		dp[1]=1;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int L=1,R=i-1;
			int ans=0;
			while(L<=R)
			{
				int mid=(L+R)/2;
				if(check(mid,a[i]))
				{
					R=mid-1;
					ans=mid;
				}
				else
				{
					L=mid+1;
				}
			}
			if(ans>0)
			{
				dp[i]=sum[i-1]-sum[i-ans-1];
			}
			sum[i]=sum[i-1]+dp[i];
			b[sum[i]]++;
			if(sum[i]>=d)
			{
				ans+=min(b[sum[i]],b[sum-d])
			}
			
		}
		cout<<ans;
	}
}
