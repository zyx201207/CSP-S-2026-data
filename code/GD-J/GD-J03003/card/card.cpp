#include <cstdio>
#define N 500005
int card[N],s[N],f[N];
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,j=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&card[i]);
	}
	int can=1;
	for(int i=1;i<n;i++)
	{
		if(card[i-1]>card[i])
		{
			can=0;
		}
	}
	if(can)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=i;k<n;k++)
			{
				if(k==0)
				{
					s[j]=card[k],j++;
				}
				else
				{
					if(card[k-1]==card[k])
					{
						continue;
					}
					else
					{
						s[j]=card[k],j++;
					}
				}
			}
			for(int k=0;k<j;k++)
			{
				f[s[k]]++;
			}
			j=0;
		}
		for(int i=2;i<=m;i++)
		{
			printf("%d ",f[i]-1);
		}
		printf("%d ",n);
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int k=i;k<n;k++)
		{
			for(int p=0;p<j;p++)
			{
				if(s[p]==card[k])
				{
					j=p;
				}
			}
			s[j]=card[k],j++;
		}
		for(int k=0;k<j;k++)
		{
			f[s[k]]++;
		}
		j=0;
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",f[i]);
	}
	return 0;
}
