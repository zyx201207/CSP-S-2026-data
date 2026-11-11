#include <cstdio>
using namespace std;
int a[500005]={},a2[500005]={},c[300005]={};
bool b[300005]={};

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j,k,f,n,m;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			a2[j]=a[j];
		for(j=1;j<=n;j++)
			b[j]=0;
		for(j=i;j<=n;j++)
		{
			if(b[a2[j]]==1)
			{
				for(k=j,f=a2[k];a2[k]!=f||k==j;k--)
					a2[k]=0;
			}
			else
				b[a2[j]]=1;
		}
		for(j=1;j<=n;j++)
		{
			if(a2[j]!=0&&b[a2[j]]==1)
			{
				c[a2[j]]+=1;
				b[a2[j]]=0;
			}
		}
	}
	for(i=1;i<=m;i++)
		printf("%d ",c[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
