#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005]={0},b[500005]={0},c[500005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i,k=1;j<=n;j++,k++)//j表示牌堆第j张牌,k表示桌面的第k张牌 
		{
			b[k]=a[j];
			for(int l=1;l<k;l++)//扫描是否重复 
			{
				if(a[j]==b[l])//判定重复 
				{
					for(int m=l;m<=k;m++)//收牌 
					{
						b[m]=0;
					}
					k=l;//指向桌面的最后一张牌 
					b[l]=a[j];//将牌放到最右侧 
					break;
				}
			}
		}
		for(int j=1;j<=n;j++)//统计 
		{
			for(int k=1;k<=n;k++)
			{
				if(b[k]==j)
				{
					c[j]++;
				}
			}
		}
		for(int j=1;j<=n;j++)//桌面清空 
		{
			b[j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=0)
			cout<<c[i]<<" ";
	}
	return 0;
}
