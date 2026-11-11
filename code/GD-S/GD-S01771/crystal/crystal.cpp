#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long vis[500005];
int maxx=-999,num=0;
inline read()
{
	int x=0,y=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			y=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*y;
}
bool cc(int x)
{
	for(int i=1;i<=num;i++)
	{
		if(a[i]==x)
		{
			return false; 
		}
	}
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		int p;
		p=read();
		if(cc(p))
		{
			num++;
			a[num]=p;
		}
		b[i]=p;
	}
	long long hua=m;
	int ans=0;
	int th=0;
	for(int i=1;i<=num;i++)
	{
		memset(vis,0,th);
		th=0;
		for(int j=1;j<=n;j++)
		{
			
			if(b[j]<=a[i])
			{
				th++;
				vis[th]=abs(a[i]-b[j]);
			}
		}
		sort(1+vis,1+vis+th);
		for(int k=1;k<=th;k++)
		{
			if(hua>=vis[k])
			{
				hua-=vis[k];
				ans++;
			}
			else
			{
				break;
			}
		}
		maxx=max(maxx,ans);
		ans=0;
		hua=m;
		
	}
	cout<<maxx;
	return 0; 
} 
