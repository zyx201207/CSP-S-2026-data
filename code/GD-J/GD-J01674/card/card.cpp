#include<cstdio>
#include<iostream>
#include<vector>
#include<stack> 
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	vector<int> Cards(n);
	for(int i=0;i<n;i++)
	{
		cin>>Cards[i];
		Cards[i]--;//减1，使点数从0开始 
	}
	vector<int> Stay(m);//Stay[i]代表留下第i张卡牌的局数 
	for(int i=0;i<n;i++)
	{
		//进行n局游戏
		vector<bool> Exist(m);//记录每个点数的卡牌是否存在 
		stack<int> Place;//被摆放的卡牌的栈 
		for(int j=i;j<n;j++)//开始摆放卡牌 
		{
			if(Exist[Cards[j]]==1)
			{
				while(!Place.empty()&&Place.top()!=Cards[j])
				{
					Exist[Place.top()]=0;//不存在 
					Place.pop();//删除卡牌，直到最右边的卡牌点数是Cards[i] 
				}
			}
			else
			{
				Place.push(Cards[j]);
				Exist[Cards[j]]=1;
			}
		}
		//游戏结束，看一看留下了哪些卡牌
		for(int j=0;j<m;j++)
		{
			if(Exist[j])Stay[j]++;
		} 
	}
	for(int i=0;i<m;i++)
	{
		cout<<Stay[i]<<" ";
	}
	return 0;
}
