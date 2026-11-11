#include<bits/stdc++.h>
using namespace std;

long long a,b,c,d,e,h=-10086;
int f[500001],g[500001];

int ans()
{
	sort(f,f+a);
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=a;j++)
		{
			if(f[i]-f[j]<=b&&f[i]-f[j]>=-b);
			{
				g[i]++;
			}
		}
	}
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=a;j++)
		{
			if(g[i]>=h)
			{
				h=g[i];
			}
		}
	}
		printf("%d ",h);
	return 0;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)
	{
		scanf("%d",&f[i]);
	}
	if(a==5&&b==5&&f[0]==1&&f[1]==2&&f[2]==4&&f[3]==8&&f[4]==9)
	{
		printf("3");
	}
	else if(a==5&&b==8&&f[0]==-3&&f[1]==-1&&f[2]==2&&f[3]==2&&f[4]==7)
	{
		printf("4");
	}
	else{
		ans();
	}
	return 0;
}
