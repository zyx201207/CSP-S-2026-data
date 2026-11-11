#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long b[200005];
long long ANS=0;
long long cmp(long long x,long long y)
{
	long long ans1=0;
	long long sum[20];
	long long i=1;
	while(x/2>0)
	{
		sum[i]=x%2;
		x/=2;
		i++;
	}
	long long sum2[20];
	long long j=1;
	while(y/2>0)
	{
		sum2[j]=y%2;
		y/=2;
		j++;
	}
	long long z=1;
	for(int s=1;s<=min(i,j);s++)
	{
		ans1+=(sum[s]&&sum2[s])*z;
		z*=2;
	}
	return ans1;
}
void dfs(int x,int i)
{
	if(x>m)
	{
		long long sum=b[1];
		for(int i=2;i<=m;i++)
		{
			sum=cmp(sum,b[i]);
			
		}
		ANS=max(ANS,sum);
		return;
	}
	if(i>n)return;
	b[x]=a[i];
	dfs(x+1,i+1);
	dfs(x,i+1);
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	if(m==1)
	{
		cout<<ans;
		return 0;
	} 
	if(m==n)
	{
		int sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum=cmp(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	else if(m==n-1)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			long long sum;
			if(i!=1)sum=a[1];
			else sum=a[2];
		    for(int j=2;j<=n;j++)
		    {
			if(j==i)continue;
			sum=cmp(sum,a[i]);
		    }
		    ans=max(sum,ans);
		}
		cout<<ans;
		return 0;
	}
	dfs(1,1);
	cout<<ANS;
	return 0; 
}
