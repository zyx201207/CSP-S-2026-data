#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long res=0,fh=1;
	char ch;
	ch=getchar();
	while(ch<'0' or ch>'9')
	{
		if(ch=='-')fh=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*fh;
}
void printtttt(long long x)
{
	if(x>=10)printtttt(x/10);
	putchar(x%10+'0');
	return ;
}
void write(long long x,bool hh)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	printtttt(x);
	if(hh)putchar('\n');
	else putchar(' ');
	return ;
}
long long c,t,n,d,ans;
long long a[200005],dis[20005],cnt[2000005];
vector<long long>s[200005];
queue<long long>q;
void bfs(long long x)
{
	for(long long i=1;i<=n;i++)dis[i]=2999999999999999999;
	for(long long i=1;i<=n;i++)cnt[i]=0;
	while(!q.empty())q.pop();
	q.push(x);
	long long now,tot;
	dis[x]=1;
	while(!q.empty())
	{
		tot=q.size();
		while(tot--)
		{
			now=q.front();
			q.pop();
			for(long long i=0;i<s[now].size();i++)
			{
				if(dis[now]+1<dis[s[now][i]])
				{
					dis[s[now][i]]=dis[now]+1;
					cnt[s[now][i]]=1;
					q.push(s[now][i]);
					//write(s[now][i],false);
				}
				else if(dis[now]+1==dis[s[now][i]])cnt[s[now][i]]++;
			}
		}
	}
	//write(x,true);
	/*for(long long i=1;i<=n;i++)write(dis[i],false);
	write(-1,true);
	for(long long i=1;i<=n;i++)write(cnt[i],false);
	write(-1,true);*/
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--)
	{
		n=read();
		d=read();
		ans=0;
		for(long long i=1;i<=n;i++)a[i]=read();
		for(long long i=1;i<=n;i++)
		{
			s[i].clear();
			for(long long j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					s[i].push_back(j);
					//write(i,false);
					//write(j,true);
				}
				else break;
			}
		}
		for(long long i=1;i<=n;i++)
		{
			bfs(i);
			for(long long j=i+1;j<=n;j++)
			{
				if(cnt[j]==2)
				{
					ans++;
					//write(i,false);
					//write(j,true);
				}
			}
		}
		write(ans,true);
		/*for(long long i=1;i<=n;i++)
		{
			write(i,false);
			putchar(':');
			write(s[i].size(),false);
			for(long long j=0;j<s[i].size();j++)write(s[i][j],false);
			putchar('\n');
		}*/
	}
	return 0;
}
/*
怎么说呢
高中的第一场CSP就这么爆炸了
T1堪比奶龙，预计只有特殊性质的30pts
T2，T4压根没打
T3这坨屎山代码估计也是0pts
希望别文件写错，不然0pts就好笑了
OI做碎信竞魂，长官我是文化人 
*/
