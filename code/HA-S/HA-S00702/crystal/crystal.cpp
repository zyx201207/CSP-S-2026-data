#include<cstdio>
using namespace std;
int n,m,ans,a[500005],x,p,t;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1]) ans++;
		else if(a[i]<a[i+1]) 
		{
			x+=a[i+1]-a[i];
			a[i]=a[i+1];
			if(x>m) p=i;
		//printf("%d",p);
		for(int j=1;j<=p;j++)
		{
			if(a[p]>=a[i]) x+=a[p]-a[i];
			else break;
		}
		if(x<=m) ans++;
		if(x>m) break;
		}
	}
	printf("%d",ans+1);
	return 0;
} 
