#include<iostream>
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		a[n-i-1]=t;
	}
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<i;j++)
		{
			if(a[j]==a[i])
			{
				n-=i-j;
				i-=i-j;
			}
		}
		for(int j=0;j<=i;j++)
		{
			b[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}
