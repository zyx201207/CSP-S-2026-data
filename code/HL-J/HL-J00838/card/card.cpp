#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000];
stack<int>s;
int vis[1144];
int ans[1144];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	for(int j = 1;j <= n;j++)
	{
		for(int i = j;i <= n;i++)
		{
			if(vis[a[i]] == 1)
			{
				s.pop();
				//s.push(a[i]);
				vis[a[i]] = 0;
			}
			s.push(a[i]);
			vis[a[i]] = 1;
			while(!s.empty())
			{
				//cout<<s.top()<<" ";
				ans[s.top()]++;
				s.pop();
			}
		}
	}
	for(int i =1;i <= m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}