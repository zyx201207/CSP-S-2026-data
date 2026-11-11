#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,maxn=-1;
	long long m;
	int a[500005];
	cin>>n>>m;
	bool f=true,g=true;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=i) f=false;
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=a[2]-a[1]) g=false;
	}
	sort(a+1,a+n+1);
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			int sum=0,cnt=0;
			for(int j=1;j<=i;j++)
			{
				cnt+=(a[i]-a[j]);
				if(cnt>m) break;
				sum++;
			}
			maxn=max(maxn,sum);
		}
		cout<<maxn;
		return 0;
	}
	if(f==true)
	{
		int cnt=1;
		while(m>=0)
		{
			m-=cnt;
			cnt++;
		}
		cout<<(m==0 ? cnt:cnt-1);
		return 0;
	}
	if(g==true)
	{
		int cnt=1,tmp=a[2]-a[1];
		while(m>=0)
		{
			m-=cnt*tmp;
			cnt++;
		}
		cout<<(m==0 ? cnt:cnt-1);
		return 0;
	}	
} 
