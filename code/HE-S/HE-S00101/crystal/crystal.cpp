#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxn=0,Maxn=-1e18,Minn=1e18;
int val=0,cost=0;
bool Sub13_15=1,Sub16_18=1;
int a[500050],sum[500050];
unordered_map<int,int>mp;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		Maxn=max(Maxn,a[i]);
		Minn=min(Minn,a[i]);
		if(a[i]!=i) Sub13_15=0;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) Sub16_18=0;
	}
	if(Sub16_18||Sub13_15)
	{
		int cost=0,val=1,pos=0;
		for(int i=2;i<=n;i++)
		{
			cost=cost+(a[i]-a[i-1])*val;
			val++;
			if(cost>m)
			{
				pos=i;
				break;
			}
		}
		cout<<pos-1;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n<=500000&&Maxn<=100)
	{
		int pos=1,cost=0,posw=0;
		for(int i=Minn;i<=Maxn;i++)
		{
			cost=0;
			for(int j=pos;j<=n;j++)
				if(a[j]>i)
				{
					pos=j;
					break;
				}
			for(int j=pos-1;j>=1;j--)
			{
				cost+=i-a[j];
				if(cost>m)
				{
					posw=j;
					break;
				}
			}
			maxn=max(maxn,pos-posw-1);
		}
		cout<<maxn;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		val=1;cost=0;
		int pos=0;
		for(int j=i+1;j<=n;j++)
		{
			cost=cost+(a[j]-a[j-1])*val;
			val++;
			if(cost>m)
			{
				pos=j;
				break;
			}
		}
		maxn=max(maxn,pos-i);
	}
	cout<<maxn;
	return 0;
}
