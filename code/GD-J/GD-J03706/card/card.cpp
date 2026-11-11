#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],pos,s[300005],p[500005],k[300005],bz;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<a[i-1])
		{
			bz++;
		}
	}
	if(!bz)
	{
		pos=1;
		s[pos]=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				s[++pos]++;
			}
			else
			{
				s[pos]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			s[i]+=s[i-1];
			printf("%d ",s[i]);
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			pos=0;
			for(int j=i;j<=n;j++)
			{
				if(k[a[j]])
				{
					for(int o=k[a[j]]+1;o<=pos;o++)
					{
						k[p[o]]=0;
					}
					pos=k[a[j]];
				}
				else
				{
					p[++pos]=a[j];
					k[a[j]]=pos;
				}
			}
			for(int j=1;j<=pos;j++)
			{
				s[p[j]]++;
				k[p[j]]=0;
			}
		}
		for(int i=1;i<=m;i++)
		{
			printf("%d ",s[i]);
		}
	}
	return 0;
}
