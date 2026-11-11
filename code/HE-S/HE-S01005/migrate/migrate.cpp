#include <iostream>
using namespace std;

const int N=5e3+10,M=1e6+10;
int c,t;
int n,d,o;
int q[N];
int dist[N];
int res[N][N];
bool st[N][N];
int q1[N];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	if(c<=10)
	{
	while(t--)
	{
		scanf("%d%d",&n,&d);
		for(int i=0;i<n;i++) scanf("%d",&q[i]);
		
		for(int i=0;i<n-1;i++) dist[i]=q[i+1]-q[i];
		
		for(int k=1;k<=d;k++)
		{
			for(int i=0;i<n-k;i++)
			{
				if(k==dist[i])
					st[i][i+k]=true;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			int u=i;
			for(int k=0;k<d;k++)
			for(int j=0;j<n;j++)
			{
				if(st[u][j])
				{
					st[u][j]=false;
					res[i][j]++;
					o++;
					if(o==d)
					{
						u=j;
						o=0;
					}
				}
			}
		}
		
		int sum=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(res[i][j]==2)
					sum++;
					
		printf("%d",sum);
	}
	}
	
	if(c==11||c==12)
	{
		while(t--)
		{
			scanf("%d%d",&n,&d);
			for(int i=0;i<n;i++) scanf("%d",&q[i]);
			
			int dist=q[1]-q[0];
			int cnt=d/dist;
			if(cnt==2) printf("%d",n-1)
			else if(cnt>3) printf("%d",1);
		}
	}
	
	return 0;
}
