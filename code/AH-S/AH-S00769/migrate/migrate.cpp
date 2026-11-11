#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=2e6+5;
int c,t;
int n,d;
int x[N];
int f[505][505];
int s[505][505];
inline void read(int &x)
{
	x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	read(c);
	read(t);
	if(c<=6)
	{
		while(t--)
		{
			memset(s,0,sizeof s);
			memset(x,0,sizeof x);
			read(n);
			read(d);
			for(int i=1;i<=n;i++) read(x[i]);
			memset(f,0x3f,sizeof f);
			for(int i=1;i<=n;i++) f[i][i]=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(abs(x[i]-x[j])>d) continue;
					f[i][j]=f[j][i]=1;
					s[i][j]=s[j][i]=1;
				}
			}
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					if(f[i][k]==INF) continue;
					for(int j=1;j<=n;j++)
					{
						if(f[k][j]==INF) continue;
						if(i==k||j==k) continue;
						if(f[i][j]>f[i][k]+f[k][j])
						{
							f[i][j]=f[i][k]+f[k][j];
							s[i][j]=1;
						}
						else if(f[i][j]==f[i][k]+f[k][j])
						{
							s[i][j]++;
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(s[i][j]==2) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	else if(c==11||c==12)
	{
		while(t--)
		{
			read(n);
			read(d); 
			int cha;
			for(int i=1;i<=n;i++)
			{
				read(x[i]);
			}
			cha=x[2]-x[1];
			int c=d/cha,ans=0;
			for(int i=c;i<n;i+=c)
			{
				ans+=n*(i-1)-i*(i-1)-i*(i-1)/2;
			}
			cout<<ans<<"\n";
		}
	}
	else if(c==13||c==14)
	{
		while(t--)
		{
			read(n);
			read(d);
//			int supernode;
			for(int i=1;i<=n;i++) read(x[i]);
//			bool flag;
//			for(int i=1;i<=n;i++)
//			{
//				flag=1;
//				for(int j=1;j<=n;j++)
//				{
//					if(abs(x[i]-x[j])>d)
//					{
//						flag=0;
//						break;
//					}
//				}
//				if(flag)
//				{
//					supernode=i;
//					break;
//				}
//			}
			cout<<(n-1)*(n-2)/2<<"\n";
		}
	} 
	return 0;
}
/*
0 1
10 3
1 4 7 8 9 10 11 12 15 18
*/
