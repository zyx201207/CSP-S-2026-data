#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long s=0;
	char ch=getchar(),f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
long long x[2000005];
int vis[2000005],dis[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c=read();
	int t=read();
	if(c==11 || c==12)
	{
		while(t--)
		{
			int n=read();
			long long d=read();
			for(int i=1;i<=n;i++)
				x[i]=read();
			d/=x[2]-x[1];
			if(d<2) puts("0");
			else write(max(0LL,1LL*n-2*d+1)),putchar('\n');
		}
		return 0;
	}
	if(c==13 || c==14)
	{
		while(t--)
		{
			int n=read();
			long long d=read();
			for(int i=1;i<=n;i++)
				x[i]=read();
			int l=1,r=n;
			while(x[n]-x[l]>d) l++;
			while(x[r]-x[1]>d) r--;
			write((l-1)*1LL*(r-l)*(n-r));
			puts("");
		}
		return 0;
	}
	while(t--)
	{
		int n=read();
		long long d=read();
		for(int i=1;i<=n;i++)
			x[i]=read();
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				dis[j]=0x3f3f3f3f,vis[j]=0;
			queue<pair<int,int>> q;
			q.push({i,0});
			dis[i]=0;
			while(!q.empty())
			{
				int p=q.front().first,w=q.front().second;
				q.pop();
				if(w>dis[p]) continue;
				if(w<dis[p]) dis[p]=w,vis[p]=1;
				else vis[p]++;
				for(int i=p+1;i<=n;i++)
				{
					if(x[i]-x[p]>d) break;
					if(w+1<=dis[i]) q.push({i,w+1});
				}
			}
			for(int j=i+1;j<=n;j++)
				if(vis[j]==2) ans++;
		}
		write(ans);
		puts("");
	}
	return 0;
}
