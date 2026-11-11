#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const int maxn=300005; 
int a[MAXN],b[MAXN],c[MAXN];
int chu[maxn];
int cnt[maxn];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k=0;
	long long w=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i]; 
	}
	for(int o=1;o<=n;o++)
	{
		k=0;
		for(int i=o-1;i<n;i++)
		{
			a[i]=c[i];
			chu[a[i]]=0;
			b[i]=0;
		}	
		for(int i=o-1;i<n;i++)
		{
			if(chu[a[i]]==0)
			{
				b[k]=a[i];
				chu[a[i]]=1;
				k++;
			}
			else if(chu[a[i]]==1)
			{
				for(int j=0;j<i;j++)
				{
					if(a[i]==a[j])
					{
						for(int l=j;l<i;l++)
						{
							b[l]=' ';
							if(chu[a[l]]!=2)
							{
								chu[a[l]]=0; 
							}
							
						}
						k=j;
						b[k]=a[j];
						chu[a[i]]=2;
						k++;
					}
					break;
				}
			}
		}
		for(int i=0;i<k;i++)
		{
			cnt[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	} 
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
