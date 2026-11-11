#include<cstdio>
#include<string>
using namespace std;
int n,m,a[1000005],ans,t;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		t=a[i]&a[i+1];
		for(int j=2;j<m;j++)
		{
			t+=t&a[i+j];
		}
		if(t>ans) ans=t;
	}
	printf("%d",ans);
	return 0;
}
