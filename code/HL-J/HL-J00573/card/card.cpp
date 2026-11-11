#include<bits/stdc++.h>
using namespace std;
int card[500009],ans[500009],point;
bool vis[500009];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>card[i];
	for(int i=1;i<=n;i++)
	{
		vector<int> table;
		int point =0;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			bool flag=0;
			while(vis[card[j]]&&table[point]!=card[j]) 
			{
				vis[table[table.size()-1]]=0;
				point--;
				table.pop_back();
				flag=1;
			}
			point++;
			table.push_back(card[j]);
			vis[card[j]]=1;
		}
		for(size_t i=0;i<table.size();i++) ans[table[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
