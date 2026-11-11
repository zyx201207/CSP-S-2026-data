#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],zx[500005],c[300005];
int h=1;
bool z[500005];
void yx(int k)
{
	for(int i=1;i<=n;i++)
	z[i]=0;
	h=1;
	for(int i=k;i<=n;i++)
	{
		if(z[a[i]]==0)
		{
			zx[h]=a[i];
			z[a[i]]=1;
			h++;
		}		
		else
		{
			h=i-k+1;
			h++;
		}
	}
	return ;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		yx(i);
		for(int j=1;j<=h;j++)
		{
			 c[zx[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	printf("%d ",c[i]);
	return 0;
}
