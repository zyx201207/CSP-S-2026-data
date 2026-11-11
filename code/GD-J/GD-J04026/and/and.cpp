#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n,m;
int a[200005];
int x[200005],y[200005],l1=0,l2=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		x[++l1]=a[i];
	}
	int ans=0;
	for(int t=30;t>=0;t--)
	{
		int cnt=0;
		for(int i=1;i<=l1;i++)
		{
			if(x[i]&(1<<t))
			{
				cnt++;
			}
		}
		if(cnt<m)
		{
			continue;
		}
		l2=0;
		for(int i=1;i<=l1;i++)
		{
			if(x[i]&(1<<t))
			{
				y[++l2]=x[i];
			}
		}
		l1=l2;
		for(int i=1;i<=l1;i++)
		{
			x[i]=y[i];
		}
		ans+=(1<<t);
	}
	printf("%d\n",ans);
	return 0;
}
