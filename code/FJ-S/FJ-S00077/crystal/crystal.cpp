#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long a[maxn],sum[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	long long c;
	bool flag1=1,flag2=1;
	long long cnt=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i) flag1=false;
		if(a[i]-a[i-1]!=c&&i>2) flag2=false;
		c=a[i]-a[i-1];
	}
	if(flag1)
	{
		cout<<((m+1)>n?n:(m+1));
		return 0;
	}
	else if(flag2)
	{
		if(c!=0) cout<<m/c+1;
		else cout<<n;
		return 0;
	}
	else
	{	
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i]+1) continue;
			int t=a[i],k=i;
			cnt=0;
			for(int j=1;j<=k;j++)
			{
				sum[j]=t-a[j];
			}
			sort(sum+1,sum+k+1);
			long long d=m;
			for(int j=1;d-sum[j]>=0&&j<=k;j++)
			{
				d-=sum[j];
				cnt++;
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
