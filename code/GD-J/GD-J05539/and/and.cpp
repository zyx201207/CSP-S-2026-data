#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,mc[105];
struct cc{
	long long gx,id;
}s[200005];
bool cmp(cc x,cc y)
{
	return x.gx>y.gx;
}
long long aa(long long x)
{
	long long sum=0,t=x;
	while(t>=1)
	{
		for(int i=31;i>=0;i--)
		{
			if(mc[i]<=t)
			{
				sum+=(i+1);
				t-=mc[i];
				break;
			}
		}
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	mc[0]=1;
	for(int i=1;i<=31;i++)
	{
		mc[i]=mc[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i].id=a[i];
		s[i].gx=aa(a[i]);
	}
	sort(s+1,s+1+n,cmp);
	if(m==1)
	{
		long long maxx=0;
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2)
	{
		long long maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					long long t=i&j;
					maxx=max(maxx,t);
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		long long maxx=a[1];
		for(int i=2;i<=n;i++)
		{
			maxx=maxx&a[i];
		}
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(i==1)
		{
			ans=s[i].id;
		}
		else
		{
			ans=ans&s[i].id;
		}
	}
	cout<<ans;
	
	
	return 0;
}
