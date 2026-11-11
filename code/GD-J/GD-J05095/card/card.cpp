#include <bits/stdc++.h>
using namespace std;
const int N = 5*1e5+5;
int n,m;
int a[N];
int b[N];//桌面上留有点数为i的牌的局数 
int c[N];//目前桌面上第i张牌的点数 
int d[N];//目前桌面上点数为i的牌的下标，若没有该点数的牌，则下标为0 
int main()
{
	//文件输入输出freopen记得写上 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		int cnt = i;//cnt表示目前打第几张牌  
		int num = 0;//num表示目前桌子上有几张牌  
		for (int j = i;j <= n;j++) 
		{
			if (d[a[cnt]] > 0)
			{
				int sum = num;
				num = num-(num-d[a[cnt]]+1);
				for (int k = d[a[cnt]];k <= sum;k++)
				{
					d[c[k]] = 0;
					c[k] = 0;
				}
			}
			num++;
			c[num] = a[cnt];
			d[a[cnt]] = num;
			cnt++;
		}
		for (int j = 1;j <= num;j++)
		{
			b[c[j]]++;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
