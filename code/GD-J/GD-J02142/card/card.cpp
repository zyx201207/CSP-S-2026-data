#include <iostream>
using namespace std;
int n,m;
int a[512345];
int tong[512345];//桶 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i<=n;i++)//场数 
	{
		int b[512345];
		for (int j=1;j<=n;j++)//数组 
		{
			b[j]=a[j];
		}
		int cnt=0;
		for (int j=i;j<=n;j++)//每局 
		{
			for (int k=i;k<=j;k++)//检验 
			{
				if (b[j]==b[k])
				{
					cnt--;
					for (int p=k;p<j;p++)//扔牌 
					{
						b[p]=0;
					}
					break; 
				}
			}
		}
		for (int j=1;j<=m;j++)
		{
			for (int k=i;k<=n;k++)
			{
				if(b[k]==j)
				{
					tong[j]++;
					break;
				}
				
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout <<tong[i]<<" ";
	}
	return 0;
}
