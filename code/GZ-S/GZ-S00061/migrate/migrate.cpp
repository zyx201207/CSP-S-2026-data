//GZ-S00061 zhangbin zunyisizhong
#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define reqq(i,a,b) for(int i=a;i>=b;i--)

ll rd()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}

const int N=3000+5;
__int128 a[N];
__int128 g[N][N];
int vis[N][N];

void floyd(int n)
{
	repp(k,1,n)
	{
		repp(i,1,n)
		{
			repp(j,1,n)
			{
				if(g[i][j]>g[i][k]+g[k][j])
				{
					g[i][j]=g[i][k]+g[k][j];
					vis[i][j]=1;
				}
				else if(g[i][j]==g[i][k]+g[k][j] && g[i][j]!=1e20)
				{
					vis[i][j]++;
				}
			}
		}
	}
} 
int n,d;
void solve()
{
	
	repp(i,1,n) repp(j,1,n) g[i][j]=1e20,vis[i][j]=0;
	
	repp(i,1,n)
	{
		a[i]=rd();
		repp(j,1,i)
		{
			int diff=a[i]-a[j];
			if(diff<0) diff=-diff;
			if(diff<=d && i!=j)
				g[i][j]=g[j][i]=1;
		}
	}
	floyd(n);
	int ans=0;
	repp(i,1,n)
	{
		repp(j,1,n) if(i!=j && vis[i][j]==2) ans++;
	}
	printf("%d\n",ans/2);
	return ;
}
bool check()
{
	sort(a+1,a+1+n);
	int diff=a[2]-a[1];
	repp(i,1,n)
	{
		if(a[i+1]!=a[i]+diff) return 0;
	}
	return 1;
}
void work()
{
	repp(i,1,n)
		a[i]=rd();
	if(check())
	{
		int diff=a[2]-a[1];
		if(diff>=d) printf("0\n");
		else
		{
			printf("%d\n",n/diff);	
		} 
	}
	else printf("0\n");
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=rd(),T=rd();
	while(T--)
	{
		n=rd(),d=rd();
		if(n<=5000) solve();
		else work();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
