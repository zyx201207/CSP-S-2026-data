#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0' or ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int num[1005];
inline void write(long long x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	int cnt=0;
	while(x)
	{
		cnt++;
		num[cnt]=x%10;
		x/=10;
	}
	for(int i=cnt;i>=1;i--)
	{
		putchar(num[i]+'0');
	}
}
const long long N=2e6+5;
long long T,c,n,d;
long long a[N];
vector<long long>v[N];
long long f[N],ex[N];
long long cnt[N],ans;
void dij(long long s)
{
	memset(f,0x3f,sizeof(f));
	memset(ex,0,sizeof(ex));
	memset(cnt,0,sizeof(cnt));
	f[s]=0;
	queue<long long>q;
	q.push(s);
	cnt[s]=1;
	while(!q.empty())
	{
		long long x=q.front();
		q.pop();
		ex[x]=0;
		for(auto y:v[x])
		{
			if(f[y]>f[x]+1)
			{
				f[y]=f[x]+1;
				cnt[y]=cnt[x];
				if(!ex[y])
				{
					ex[y]=1;
					q.push(y);
				}
			}
			else if(f[y]==f[x]+1)
			{
				cnt[y]+=cnt[x];
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		if(cnt[i]==2)
		{
			ans++;
		}
	}
}
void solve()
{
	n=read();d=read();
	for(long long i=1;i<=n;i++)
	{
		a[i]=read();
		v[i].clear();
	}
	for(long long i=1;i<=n;i++)
	{
		long long l=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		for(long long j=i+1;j<=l;j++)
		{
			v[i].push_back(j);
			v[j].push_back(i);
		}
	}
	ans=0;
	for(long long s=1;s<=n;s++)
	{
		dij(s);
	}
//	printf("%lld\n",ans/2);
	write(ans/2);
	putchar('\n');
}
void solve1()
{
	n=read();d=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	if(a[2]-a[1]>=d or a[3]-a[1]>d)
	{
		putchar('0');
		putchar('\n');
		return;
	}
	write(n-(a[2]-a[1])/2);
	putchar('\n');
} 
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		if(c<=10) solve();
		else solve1();
	}
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
