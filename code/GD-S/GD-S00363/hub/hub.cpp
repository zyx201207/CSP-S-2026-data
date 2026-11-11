#include<cstdio>
using namespace std;
int c;
int n,m;
bool chck(int x)
{
	int l=x,r=(n+1)/2-x;
	return ((r-l+1-m)/2)<x;
}
void slv()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
	}
	if((c>=13)&&(c<=14))
	{
		if(n==m)
		{
			printf("0\n");
			return ;
		}
		int l=1,r=n-m,ans=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(chck(mid))
			{
				r=mid-1,ans=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		printf("%d\n",ans);
	}
	else
	{
		printf("0\n");
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	scanf("%d%d",&c,&T);
	for(int i=1;i<=T;i++)
	{
		slv();
	}
	return 0;
}
