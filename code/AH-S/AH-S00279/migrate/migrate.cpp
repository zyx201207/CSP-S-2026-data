#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2000010;
vector<int> G[5010];
int c, T, n, d, x[maxn], dis[maxn], t[maxn], ans, l[maxn], r[maxn], d1[maxn], d2[maxn];
int read()
{
	int res = 0, f = 1;
	char c = getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-') f = -1;
		c = getchar();
	}
	while(c>='0' && c<='9')
	{
		res = res*10+c-'0';
		c = getchar();
	}
	return f*res;
}
void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	while(T--)
	{
		ans = 0;
		n=read();d=read();
		for(int i=1;i<=n;i++)
			x[i] = read(), l[i] = r[i] = i;
		if(c<=10)
		{
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(x[j]-x[i]<=d)
						l[j] = min(l[j], i), r[i] = max(r[i], j);
			for(int i=1;i<=n;i++)
			{
				dis[i] = 0;
				t[i] = 1;
				for(int j=i+1;j<=n;j++)
					dis[j] = maxn, t[j] = 0;
				for(int j=i+1;j<=n;j++)
				{
					dis[j] = dis[max(l[j], i)]+1;
					for(int k=max(l[j],i);k<j;k++)
					{
						if(dis[j]==dis[k]+1)
							t[j] += t[k];
						else
							break;
						if(t[j]>2)
						{
							t[j] = 3;
							break;
						}
					}
					if(t[j]==2) ans++;
				}
				/*
				cout<<"Point "<<i<<":"<<endl;
				for(int j=i;j<=n;j++)
				{
					cout<<dis[j]<<" "<<t[j]<<endl;
				}
				*/
			}
			/*
			for(int i=1;i<=n;i++)
				cout<<"L:"<<l[i]<<"R:"<<r[i]<<endl;
			*/
			write(ans);
			puts("");
		}
		else
		{
			ans = 0;
			int k = d/(x[2]-x[1]);
			if(x[2]-x[1]>=d)
			{
				putchar('0');
				puts("");
				continue;
			}
			for(int i=1;i<=n;i++)
			{
				d1[i] = 1, d2[i] = 0;
				int u1 = i-k*2;
				if(u1>0) d1[i] += d1[u1], d2[i] += d2[u1];
				int u2 = i-k*2+1;
				if(u2>0) d2[i] += d1[u2];
				ans += d2[i];
				//if(n<=10)
				//cout<<"I:"<<i<<" "<<d1[i]<<" "<<d2[i]<<" "<<u1<<" "<<u2<<endl;
			}
			write(ans);
			puts("");
		}
	}
	return 0;
}
