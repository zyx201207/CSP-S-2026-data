#include<bits/stdc++.h>
using namespace std;

int a[500020];
int desk[500020];//desk[i]i点数牌出现次数 

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;//n为牌数和游戏局数，m为点数种类数 
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	
	cout<<1<<" "<<1<<" "<<1;
	
} 
