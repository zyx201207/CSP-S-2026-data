#include<bits/stdc++.h>//36·Ö 
using namespace std;
int n,m,a[500005],w[500005],ans[500005];//s[500005],d[300005][500005],tmp[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		/*s[a[i]]++;
		if(s[a[i]]>=2)
		{
			for(int j=tmp[a[i]];j>=1;j--)
			{
				if(d[a[i]][j]!=0)break;
				d[a[i]][j]=i;
			}
		}
		tmp[a[i]]=i;*/
	}
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)printf("%d ",d[i][j]);
		printf("\n");
	}
	return 0;*/
	for(int k=1;k<=n;k++)
	{
		
		memset(w,0,sizeof(w));
		for(int i=k;i<=n;i++)
 		{
			if(w[a[i]])
			{
				for(int j=i-1;j>=1;j--)
				{
					w[a[j]]=0;
					if(a[j]==a[i])break;
				}
			}
			w[a[i]]=1;
		}
		for(int i=1;i<=m;i++)
		{
			if(w[i]>0)ans[i]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
