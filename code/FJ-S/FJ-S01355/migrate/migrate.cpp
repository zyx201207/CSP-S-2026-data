#include<bits/stdc++.h>
using namespace std;
int read()
{
	int fu=1;
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') fu=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return fu*res;
}
long long llread()
{
	int fu=1;
	long long res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') fu=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return fu*res;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x<=9)
	{
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
const int N=5003;
int t;
long long x[N];
int f[N][N],cnt[N][N];
void solve1()
{
	t=read();
	while(t--)
	{
		int n=read();
		long long d=llread();
		for(int i=1;i<=n;i++)
		{
			x[i]=llread();
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(x[i]-x[j])<=d) f[i][j]=1;
				else f[i][j]=0x3f3f3f3f;
				cnt[i][j]=1;
			}
		}
		int ans=0;
		for(int l=2;l<n;l++)
		{
			for(int i=1;i+l<=n;i++)
			{
				int j=i+l;
				//cout<<i<<' '<<j<<endl;
				if(f[i][j]==1)
				{
					continue;
				}
				for(int k=i+1;k<j;k++)
				{
					if(f[i][k]==0x3f3f3f3f) break;
					if(f[k][i]==0x3f3f3f3f) continue;
					int nd=f[i][k]+f[k][j];
					if(nd<f[i][j])
					{
						f[i][j]=nd;
						cnt[i][j]=1;
					}
					else if(nd==f[i][j])
					{
						cnt[i][j]++;
					}	
				}
			}
		}
		for(int i=1;i<n-1;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				//cout<<i<<' '<<j<<' '<<f[i][j]<<' '<<cnt[i][j]<<endl;
				if(cnt[i][j]==2) ans++;
			}
		}
		write(ans);
		cout<<endl;
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read();
	if(0<=c&&c<=10) solve1();
	return 0;
}//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
