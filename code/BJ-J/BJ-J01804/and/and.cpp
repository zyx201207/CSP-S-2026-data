#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y)
{
	return x>y;
}
long long awy(long long x,long long y)
{
	string a,b;
	long long cnt=0;
	while(x!=0)
	{
		x%=2;
		x/=2;
		cnt++;
		a[cnt]=x%2;
	}
	cnt=0;
	while(y!=0)
	{
		y%=2;
		y/=2;
		cnt++;
		b[cnt]=y%2;
	}
	long long sumk=0;
	long long sums=1;
	int minn=min(a.length(),b.length());
	for(int i=1;i<=minn;i++)
	{
		if(a[i]==b[i])
		{
			sumk+=sums;
		}
		sums*=2;
	}
	return sumk;
}
long long a[200050];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ans=-1e9;
	bool flag=0;
	long long fans=0;
	for(long long i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			if(m-2!=0)
			{
				if(i-m+2>=0&&i+m-1<=n)
				{
					long long w,k;
					for(int j=i-m+2;j<=i-1;j++)
					{
						w=awy(a[j],a[j+1]);
					}
					for(int j=i;j<=i+m-3;j++)
					{
						k=awy(a[j],a[j+1]);
					}
					ans=max(ans,w);
					ans=max(ans,k);
				}
				else if(i-m+2>=0&&i+m-1>=n)
				{
					long long w;
					for(int j=i-m+2;j<=i-1;j++)
					{
						w=awy(a[j],a[j+1]);
					}
					ans=max(ans,w);
				}
				else 
				{
					long long k;
					for(int j=i;j<=i+m-3;j++)
					{
						k=awy(a[j],a[j+1]);
					}
					ans=max(ans,k);
				}
			}
			flag=1;
			fans=max(fans,a[i]);
		}
		else
		{
			ans=a[1];
			for(int i=2;i<=m-1;i++)
			{
				ans=awy(ans,a[i]);
			}
		}
	}
	if(flag==1){
		cout<<fans;
		return 0;
	}
	cout<<ans<<" ";
	return 0;
}
