#include<bits/stdc++.h>
using namespace std;
int n,m;
int card[500005];//牌堆 
bool isin[300005];//牌在否情况 
int last_card[500005];//点数为i的卡牌最后出现几次 
vector<int> lst;//打出的牌 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
	}
	for(int i=1;i<=m;i++)//局数 
	{
		for(int j=i;j<=n;j++)//打牌 
		{
			if(!isin[card[j]])//若打出的中没有此牌 
			{
				lst.push_back(card[j]);//出牌 
				isin[card[j]]=1;//标记 
			}
			else
			{
				while(lst[lst.size()-1]!=card[j]) 
				{
					lst.pop_back();//删除牌 
				}
			}
		}
		for(int i=0;i<lst.size();i++) last_card[lst[i]]++;//登记 
		while(!(lst.empty())) lst.pop_back();//清空牌 
		for(int i=1;i<=m;i++) isin[i]=0;//重启状态 
	}
	for(int i=1;i<=m;i++)
	{
		cout<<last_card[i]<<' ';//输出 
	}
}
