#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int f[2000100];
int cnt=0,mi=10000,fl=0;
void dfs(int l,int r,int x)
{
	if(fl)return;
	if(f[l]>=r)
	{
		if(mi<x)return;
		mi=x;
		cnt++;
		if(cnt>2)fl++;
		return;
	}
	for(int i=f[l];i>l;i--)dfs(i,r,x+1);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	
	while(t--)
	{
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];	
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		if(a[n]-a[1]<=d)
		{
			cout<<0<<endl;
			continue;
		}
		if(n>100)continue;
		a[0]=-0x3f3f3f3f3f3f3f3f;
		a[n+1]=0x3f3f3f3f3f3f3f3f;
		if(c==11||c==12)
		{
			long long dis=a[2]-a[1];
			d=d/dis;
			if(d<2)
			{
				cout<<0<<endl;
				continue;
			}
			long long ans=0;
			ans=n-(d*2-1);
			ans=max(ans,(long long)0);
			cout<<ans<<endl;
			continue;
		}
		if(c==13||c==14)
		{
			int mid;
			long long ans=0;
			for(int i=1;i<=n;i++)if(a[i]-d<=a[1]&&a[i]+d>=a[n])mid=i;
			long long a1=0,a2=0,a3=0,a4=0;
			for(int i=1;i<=mid;i++)
			{
				if(a[i]+d>=a[mid+1]&&a[i]+d<a[mid+2])a1++;
				if(a[i]+d<a[mid+1])a2++;
			}
			for(int i=mid+1;i<=n;i++)
			{
				if(a[i]-d<=a[mid-1]&&a[i]-d>a[mid-2])a3++;
				if(a[i]-d>a[mid-1])a4++;
			}
			ans=a1*a4+a2*a3;
			cout<<ans<<endl;
			continue;
		}
		if(c==1||c==2)
		{
		int r=0;
		for(int i=1;i<=n;i++)
		{
			while(a[i]+d>=a[r])r++;
			f[i]=r-1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<d)continue;
			cnt=0,mi=10000,fl=0;
			dfs(i,j,0);
			if(cnt==2)ans++;
		}
		cout<<ans<<endl;
		continue;
		}
	}
		
	
	return 0;
}
