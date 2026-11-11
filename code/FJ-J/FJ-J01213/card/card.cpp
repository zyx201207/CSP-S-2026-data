#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int tong[3][300005];
int zhuomian[500005],now=1;
int ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n >>m;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	for(int y=1;y<=n;y++)
	{
		for(int i=y;i<=n;i++)
		{
			if(tong[1][a[i]]==0)
			{
				tong[1][a[i]]=1;
				tong[2][a[i]]=now;
				zhuomian[now]=a[i];
				now++;
			}
			else if(tong[1][a[i]]==1)
			{
				for(int j=now;j>tong[2][a[i]];j--)
				{
					tong[1][zhuomian[j]]=0;
					tong[2][zhuomian[j]]=0;
					zhuomian[j]=0;
					now=j;
				}
			}
			//for(int j=1;j<=now;j++)
			//{
			//	cout <<zhuomian[j] <<" ";
			//}
			//cout <<endl;
		}
		int i=1;
		while(zhuomian[i])
		{
			ans[zhuomian[i]]++;
			zhuomian[i]=0;
			i++;
		}
		for(int i=1;i<=m;i++)
		{
			tong[1][i]=0;
			tong[2][i]=0;
		}
		now=1;
		//cout <<"½áÊø!" <<endl; 
	}
	for(int i=1;i<=m;i++)
	{
		cout <<ans[i] <<" ";
	}
	return 0;
}























//AC!
