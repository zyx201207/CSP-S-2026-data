#include<bits/stdc++.h>
using namespace std;
bool vis1,vis2;
long long a[500050],c[500050],sum,cnt,ans,cnt1;
long long n,m;
long long tong[210];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==a[1])cnt1++;
		if(abs(a[i])>100)vis1=true;
	}
	for(int i=cnt1+1;i<=n;i++)
	{
		c[i]=a[i]-a[i-1];
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n<=5000)
	{
		long long k=2,cnt2=0;
		for(k;k<=n;k++)
		{
			cnt=0;
			for(int j=1;j<k;j++)
			{
				cnt+=(a[k]-a[j]);
			}
			ans=k-1;
			if(cnt>m)break;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[k])cnt2++;
		}
		long long sheng=m-sum;
		long long cha=a[k]-a[k-1];
		cout<<max(k-1,min(k-1,sheng/cha+cnt2));
		return 0;
	}
	else if(vis1==false)
	{
		long long minn=1000;
		for(int i=1;i<=n;i++)
		{
			a[i]+=100;
			tong[a[i]]++;
			minn=min(minn,a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			cnt=0;
			for(int j=minn;j<a[i];j++)
			{
				cnt+=tong[j]*(a[i]-j);
			}
			ans=i-1;
			if(cnt>m)break;
		}
		cout<<ans;
		return 0;
	}
	else
	{
		ans=0;
		long long cnt2=0;
		long long k=cnt1+1;
		for(k;k<=n;k++)
		{
			sum+=c[k]*(k-1);
			if(sum>m)
			{
				break;
			}
			sum-=c[k]*(k-1);
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[k])cnt2++;
		}
		long long sheng=m-sum;
		long long cha=a[k]-a[k-1];
		cout<<max(k-1,min(k-1,sheng/cha+cnt2));
		return 0;
	}
}
