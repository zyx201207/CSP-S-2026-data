#include<iostream>
#define int long long
using namespace std;
inline int read(){char cc=getchar();int z=0,fh=1;while((cc<'0' || cc>'9') && cc!='-'){cc=getchar();}if(cc=='-'){fh=-1;cc=getchar();}while(cc>='0' && cc<='9'){z=z*10+cc-'0';cc=getchar();}return z*fh;}
inline void write(int x){if(x==0){putchar('0');return ;}if(x<0){x=-x;putchar('-');}int z[20],tt=0;while(x){z[++tt]=x%10;x/=10;}for(int i=tt;i;i--){putchar('0'+z[i]);}}
const int N=2e6+5;
int c,n,d;
int x[N];
int rc[N];
int mn[N],cnt[N];
inline void zy(int i)
{
	for(int j=i+1;j<=rc[i];j++)
	{
		int z=mn[i]+1;
		if(z<mn[j])
		{
			mn[j]=z;
			cnt[j]=cnt[i];
		}
		else if(z==mn[j])
		{
			cnt[j]+=cnt[i];
		}
	}
}
inline void init()
{
	n=read(),d=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	if(c==11 || c==12)
	{
		putchar('0');
		putchar('\n');
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		int l=i+1,r=n,best=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(x[mid]-x[i]<=d)
			{
				best=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		rc[i]=best;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		mn[i]=0,cnt[i]=1;
		for(int j=i+1;j<=n;j++)
		{
			mn[j]=1e18;
			cnt[j]=0;
		}
		zy(i);
		for(int j=i+1;j<=n;j++)
		{
			zy(j);
			if(cnt[j]==2) ++ans; 
		}
	}
	write(ans);
	putchar('\n');
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	int t=read();
	while(t--)
	{
		init();
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/
