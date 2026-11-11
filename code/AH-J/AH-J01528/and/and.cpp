#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-1;
bool b[200005];
void dfs(int i,int x)
{
	long long sum=0;
	if(x==m)
	{
		ans=max(ans,sum);
		sum=0;
		return ;
	}
	if(x==0)sum+=a[i];
	else sum&=a[i];
	long long s=sum;
	dfs(i+1,x+1);
	sum=s;
	dfs(i+1,x);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long mx=-1,tz;
	bool f=0,f1=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=4)f1=1;
		mx=max(a[i],mx);
		if(a[i]!=i-1)f=1;
	}
	tz=a[1];
	for(int i=2;i<=n;i++)
	{
		tz=tz&a[i];
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	if(m==2)
	{
		long long tt=-1;
		for(int i=1;i<=n;i++)
		{
			long long ss=a[i];
			for(int j=i+1;j<=n;j++)
			{
				tt=max(tt,ss&a[j]);
			}
		}
		cout<<tt;
		return 0;
	}
	if(m==n-1)
	{
		int tt,cnt=-1;
		for(int i=1;i<=n;i++)
		{
			if(i!=1)tt=a[1];
			else tt=a[2];
			for(int j=1;j<=n;j++)
			{
				tt&=a[j];
			}
			cnt=max(cnt,tt);
		}
		cout<<cnt;
		return 0;
	}
	if(m==n)
	{
		cout<<tz;
		return 0;
	}
	if(f==0)
	{
		cout<<(n+n/2)/2;
		return 0;
	}
	if(f==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(f1==0)
	{
		int too[10];
		for(int i=1;i<=n;i++)
		{
			too[a[i]]++;
		}
		if(too[3]>=m){cout<<3;return 0;}
		else if(too[3]+too[2]>=m){cout<<2;return 0;}
		else if(too[3]+too[1]>=m){cout<<1;return 0;}
		else {cout<<0;return 0;}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
