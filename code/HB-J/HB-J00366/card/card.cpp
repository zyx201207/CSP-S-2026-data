#include<bits/stdc++.h>
using namespace std;
int m,n,o,we,pai[500005],zhuo[500005],dian[300005];
struct ton
{
	int num;
	int wei;
}tong[300005];
void clear1(int x,int y)
{
	for(int i=x;i<=y;i++)
	{
		tong[zhuo[i]].num=0;
		tong[zhuo[i]].wei=0;
		zhuo[i]=0;
	}
	return ;
}
void clear2()
{
	for(int i=1;i<=300005;i++)
	{
		tong[i].num=0;
		tong[i].wei=0;
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
		scanf("%d",&pai[i]);
	}
	for(int i=1;i<=n;i++)
	{
		clear1(1,n-i+3);
		clear2();
		o=i-1;
		for(int j=i;j<=n;j++)
		{
			o++;
			if(tong[pai[j]].num==0)
			{
				zhuo[o]=pai[j];
				tong[zhuo[o]].num++;
				tong[zhuo[o]].wei=o;
			}
			else
			{
				we=tong[zhuo[o]].wei;
				clear1(we,o+1);
				o=we;
				zhuo[o]=pai[j];
				tong[zhuo[o]].num++;
				tong[zhuo[o]].wei=o;
			}
		}
		for(int j=1;j<=o;j++)
		{
			dian[zhuo[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",dian[i]);
	}
	return 0;
}
