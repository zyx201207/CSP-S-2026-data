#include<bits/stdc++.h>
using namespace std;
bool mi44g(int a[],int x,int y,int z, int d)
{
	for(int i = x + 1;i <= 1;i++)
	{
	}
	 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		int n, d, ans = 0;
		cin >> n, d;
		int x[n + 10];
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 3;j <= n;j++)
			{
				for(int k = 1;k < j - i - 1;k++)
				{
					if(mi44g(x, i, j, k, d))
					{
						ans++;
					}
				}
			}
		}
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
djdhjddhjdhjdhhjdhdhdbchdcbgdvvdcvcdgvcdghvhgvghvdhgvhgdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddh+ 1 (1 ≤ i ≤ n 1) 行包含两个正整数 ui
, vi，分别表示第 i 条道路连接的两
座城市的编号
【输出格式】
输出到文件 hub.out 中。
对于每组测试数据，输出一行一个非负整数，表示所有合理的建造方案的通勤半径
的最小值












*/
