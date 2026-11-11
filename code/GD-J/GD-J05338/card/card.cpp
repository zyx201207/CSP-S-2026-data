#include <bits/stdc++.h>
using namespace std;
int a[100005],cnt[100005];
int game(int i,int n)
{
	stack<int> sta;
	int use[100005];//记录是否使用a[i]点数的牌 
	for(int k = 1;k <= n;k++)
		use[k] = 0;
	for(;i <= n;i++)
	{
		if(use[a[i]] == 0)//若未使用，入栈并标记 
		{
			sta.push(a[i]);
			use[a[i]] = 1;
		}
		else
		{
			for(int l = 1;l <= n;l++)
			{
				if(use[a[i]] == 0)
				 	break;
				use[sta.top()] = 0;
				sta.pop();
			}
			sta.push(a[i]);//拿走后入栈 
			use[a[i]] = 1;//标记 
		}
	}
	while(!sta.empty())
	{
		cnt[sta.top()]++;//统计 
		sta.pop();
	}
	return 0;
}
int main()
{
	int n,m;
	cin >> n >> m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		game(i,n);
	}
	for(int i = 1;i <= m;i++)//遍历点数 
	{
		cout << cnt[i] << " ";
	}
	return 0;
	
} 
