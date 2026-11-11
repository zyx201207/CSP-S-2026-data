#include<bits/stdc++.h>
using namespace std;

const int N=2e6+5;
const int M=5e3+5;
int c,t;
int n;
long long d;
long long a[N];
long long ans;
int cnt[M][M];
int num[M][M];
bitset<M>vis;

int lowerbound(int l,int r,long long x)
{
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(a[mid]<=x) l=mid+1;
		else r=mid;
	}
	return l-1;
}

void abc(int x)
{
	if(x==n) return;
	vis[x]=1;
	int x1=lowerbound(1,n+1,a[x]+d);
	if(x1==x) return;
	abc(x1);
	for(int i=x+1;i<=n;i++) num[x][i]=num[x1][i]+1;
}

void dfs(int x,int kkksc03,int from)
{
	if((num[from][x]==kkksc03)&&kkksc03) cnt[from][x]++;
//	printf("%d %d %d %d\n",from,x,kkksc03,num[from][x]);
	for(int i=x+1;i<=n&&a[i]-a[x]<=d;i++)
	{
		dfs(i,kkksc03+1,from);
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		memset(num,0,sizeof(num));
		memset(cnt,0,sizeof(cnt));
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		a[n+1]=0x7fffffffffffffff;
		if(c<=10)
		{
			vis&=0;
			for(int i=1;i<=n;i++)
				if(!vis[i]) abc(i);
//			printf("gugugaga\n");
//			for(int i=1;i<=n;i++)
//				for(int j=i+1;j<=n;j++)
//					printf("%d %d %d\n",i,j,num[i][j]);
//			printf("dagoujiao\n");
			for(int i=1;i<=n;i++)
			{
				dfs(i,0,i);
			}
//			printf("hajimi\n");
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
				{
//					printf("%d %d %d\n",i,j,cnt[i][j]);
					if(cnt[i][j]==2) ans++;
				}
		}
		if(c>=13&&c<=14)
		{
			for(int i=1;i<=n;i++)
			{
				int x1,x2,x3;
				x1=lowerbound(1,n+1,a[i]+d);
				if(x1<=i+1) continue;
				x2=lowerbound(1,n+1,a[x1-1]+d);
				x3=lowerbound(1,n+1,a[x1-2]+d);
				ans+=x2-x3;
//				printf("%d %lld\n",i,ans);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
