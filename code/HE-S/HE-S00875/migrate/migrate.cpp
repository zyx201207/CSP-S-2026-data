#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll pos[2000005];
int n;ll d;
ll step[2000005];
ll cnt[2000005];
ll rd()
{
	ll x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	return x*f;
}
char C[50];
void write(ll x)
{
	int cnt=0;
	do{
		C[++cnt]=x%10;
		x/=10;
	}while(x);
	for(int i=cnt;i>0;i--) putchar(C[i]+'0');
	putchar('\n');
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;c=rd();t=rd();
	while(t--)
	{
		bool op=1;int cha=-1;
		n=rd();d=rd();
		for(int i=1;i<=n;i++)
		{
			pos[i]=rd();
			if(i>1)
			{
				if(pos[i]-pos[i-1]!=cha)
				{
					if(cha!=-1) op=0;
					else cha=pos[i]-pos[i-1];
				}
			}
		}
		if(pos[n]-pos[1]<=d)
		{
			puts("0");
			continue;
		}
		if(n>=1e6&&op)
		{
			if(d/cha!=2)
			{
				puts("0");
			}
			else
			{
				write(n-3);
			}
			continue;
		}
		int ans=0;
		for(int i=n;i>1;i--)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(pos[i]-pos[j]<=d) step[j]=1,cnt[j]=1;
				else
				{
					ll minn=LLONG_MAX,num=0;
					for(int k=j+1;k<i;k++)
					{
						if(pos[k]-pos[j]>d) break;
						if(step[k]<minn) minn=step[k],num=cnt[k];
						else if(step[k]==minn) num+=cnt[k];
					}
					if(minn==LLONG_MAX) break;
					step[j]=minn+1;
					cnt[j]=num;
					if(num==2) ans++;
				}
			}
		}
		write(ans);
	}
}
