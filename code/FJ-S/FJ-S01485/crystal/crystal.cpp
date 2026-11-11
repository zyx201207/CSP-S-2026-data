#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long c[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;bool flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		
		b[i]=a[i]-a[i-1];
		if(b[i]!=b[i-1]&&i!=1&&i!=2)
		{
			flag=1;
		}
	}
	
if(flag==0||n>5000)
{
	long long cha=b[2]-b[1];
	long long z=0;long long ddd=1;
	for(int i=2;i<=n;i++)
	{
		if(z*2+b[i]<=m)
		{
			z=z*2+b[i];
			ddd=i;
		}
		
		
	}
	cout<<ddd;
	return 0;
}
if(n<=5000)
{
	
	long long maxx=-1e13;
	//i ok;cnt ok;
	for(int k=1;k<=n;k++)
	{
		memset(c,0,sizeof(c));
		int cnt=1;
		for(int i=1;i<=n;i++)
		{
			if(i==k)continue;
			if(a[i]>a[k])break;
			c[cnt]=a[k]-a[i];
			
			cnt++;
			
		}
		
		
		sort(c+1,c+cnt+1);
		
		long long ans=0;long long ks;
		for(int i=2;i<=cnt;i++)
		{
			if(ans+c[i]<=m)
			{
				ans+=c[i];
				//cout<<ans;
				ks=i;
			}
			
		}
	
		maxx=max(maxx,ks);
	}
    
	cout<<maxx;
}

	return 0;
} 

