#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int maxn=2*1e6+5;
int c,t,n,d,x[maxn],dist[maxn],cnt[maxn];
int read()
{
	int num=0,sign=1;
	char ch=getchar();
	while(ch<'0' or ch>'9')
	{
		if(ch=='-')
			sign=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9')
	{
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*sign;
}
void print(int p)
{
	if(p<0)
		putchar('-'),p=-p;
	if(p/10)
		print(p/10);
	putchar(p%10+'0'); 
}
inline int _dis(int a,int b)
{
	a=x[a],b=x[b];
	return max(b-a,a-b);
}
void bfs(int start)
{
	memset(dist,0x3f,sizeof dist);
	memset(cnt,0,sizeof cnt);
	dist[start]=0;
	cnt[start]=1;
	queue<int> q;
	q.push(start);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(i==u or _dis(i,u)>d)
				continue;
			if(dist[u]+1<dist[i])
			{
				dist[i]=dist[u]+1;
				cnt[i]=cnt[u];
				q.push(i);
			}
			else if(dist[u]+1==dist[i])
				cnt[i]+=cnt[u];
		}
	}
}
void solve()
{
	n=read();
	d=read();
	for(int i=1;i<=n;i++)
		x[i]=read();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		for(int j=1;j<=n;j++)
		{
			//print(cnt[j]),putchar(' ');
			if(cnt[j]==2)
				ans++;	
		}
	}
	ans/=2;
	print(ans);
	putchar('\n');
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	c=read();
	t=read();
	while(t--)
		solve();
	return 0;
}
