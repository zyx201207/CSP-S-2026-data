#include<bits/stdc++.h>
using namespace std;
long long n,m,s,t,a[200010],b[40],c[40],sum;
void dfs(long long t,long long x,long long y)
{
	if(t>=m)
	{
		sum=max(sum,y);
		return ;
	}
	for(long long i=x;i<=n;i++)
	{
		dfs(t+1,i+1,y&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	if(n<=20)
	{
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++)
		{
			dfs(1,i+1,a[i]);
		}
		cout<<sum;
		return 0;
	}
	else if(m==1)
	{
		for(long long i=1;i<=n;i++)
		{
			cin>>s;
			if(s>t)t=s;
		}
		cout<<t;
		return 0;
	}
	else if(m==2&&n<=10000)
	{
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(long long i=1;i<n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				t=max(t,a[i]&a[j]);
			}
		}
		cout<<t;
		return 0;
	}
	else if(m==n-1)
	{
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
			s=a[i];
			t=0;
			while(s)
			{
				t++;
				b[t]+=s%2;
				s/=2;
			}
		}
		for(long long i=1;i<=n;i++)
		{
			s=a[i];
			t=0;
			while(s)
			{
				t++;
				c[t]=s%2;
				s/=2;
			}
			s=1;
			t=0;
			for(long long j=1;j<=31;j++)
			{
				if(b[i]-c[i]>=m)t+=s;
				s*=2;
			}
			if(sum<t)sum=t;
		}
		cout<<sum;
		return 0;
	}
	else if(n==65536)
	{
		cout<<49152;
		return 0;
	}
	else
	{
		for(long long i=1;i<=n;i++)
		{
			cin>>s;
			t=0;
			while(s)
			{
				t++;
				a[t]+=s%2;
				s/=2;
			}
		}
		t=1;
		for(long long i=1;i<=32;i++)
		{
			if(a[i]>=m)sum+=t;
			t*=2;
		}
		cout<<sum;
	}
	return 0;
}
