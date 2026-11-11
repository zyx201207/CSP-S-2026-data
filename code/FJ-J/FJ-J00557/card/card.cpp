#include<bits/stdc++.h>
using namespace std;
struct node
{
	int num;
	bool is;
}a[500005],ans[300005];
int n,m,game=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num;
		a[i].is=1;
	}
	while(game<=n)
	{
		for(int i=1;i<=m;i++)
		{
			ans[i].is=1;
		}
		queue<int>q;
		int point=game;
		while(point<=n)
		{
			if(ans[a[point].num].is)
			{
				q.push(a[point].num);
			    ans[a[point].num].is=0;
			}
			else
			{
				queue<int>q1;
				while(q.front()!=a[point].num)
				{
					q1.push(q.front());
					q.pop();
				}
				while(!q.empty())
				{
					ans[q.front()].is=1;
					q.pop();
				}
				while(!q1.empty())
				{
					q.push(q1.front());
					q1.pop();
				}
				q.push(a[point].num);
				ans[a[point].num].is=0;
			}
			point++;
		}
		while(!q.empty())
		{
			ans[q.front()].num++;
			q.pop();
		}
		game++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i].num<<' ';
	}
}
