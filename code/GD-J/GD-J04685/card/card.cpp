#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[500005],b[500005]={0},k=0,l[500005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]); 
	}
	for(int i=1;i<=n;i++)
	{
		k=0;
		for(int j=i;j<=n;j++)
		{
			if(l[a[j]]>k||l[a[j]]==0)
			{
				k++;
				l[a[j]]=k;
				b[k]=a[j];
			}
			else
			{
				k=l[a[j]];
			}
		}
		for(int j=1;j<=k;j++)
		{
			s[b[j]]++;
			l[b[j]]=0;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",s[i]);
	}
	return 0;
}
