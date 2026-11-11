#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int card[500100];
struct POINT{
	bool is;//有没有
	int p;//在哪 
};
POINT used[300100];
int tong[300100];
vector<int> desk;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
	}
	int desklen=0;
	for(int round=1;round<=n;round++)//对于每局游戏
	{
		while(desk.size()!=0)
		{
			desk.pop_back();
		}
		for(int i=1;i<=m;i++)
		{
			used[i].is=0;
		}
		//cout<<"round"<<round<<endl;
		for(int j=1+round-1;j<=n;j++) //对于每张卡牌 
		{
			//cout<<"现在打出的是"<<card[j]<<endl;
			//cout<<"used中的该点数的使用情况为："<<used[card[j]].is<<endl;
			if(used[card[j]].is==0)
			{
				//cout<<"没有同点数的卡"<<endl;				
				used[card[j]].is=1;
				used[card[j]].p=desk.size();
			}
			else
			{	
				//cout<<"有同点数的卡,位置在"<<used[card[j]].p<<endl;
				int t=desk.size()-used[card[j]].p;
				//cout<<"需要从尾部删除"<<t<<"张卡牌"<<endl;
				while(t--)
				{
					used[desk[desk.size()-1]].is=0;
					//cout<<"删除"<<desk[desk.size()-1]<<"清空used中的该点数的使用情况"<<endl;
					desk.pop_back();
					
					
					
				}
//				cout<<"删除后的牌桌"<<endl;
//				for(int i=0;i<desk.size();i++)
//				{
//					cout<<desk[i]<<" ";
//				}
//				cout<<endl;
			}
			
			
			desk.push_back(card[j]);
			used[card[j]].is=1;
			//cout<<"打出新卡后的牌桌"<<endl;
//			for(int i=0;i<desk.size();i++)
//			{
//				cout<<desk[i]<<" ";
//			}
//			cout<<endl;
		}
		for(int i=0;i<desk.size();i++)
		{
			tong[desk[i]]++;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<tong[i]<<" ";
	}
	cout<<endl;	
	
	//10 3 3 1 2 1 3 2 3 1 2 1
	
	
	return 0;
}
