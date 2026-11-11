#include <bits/stdc++.h>
using namespace std;
int n,m,f[300005],e[300005],ans=0;
//f记录同一花色牌数，e记录同一花色牌出现次数，ans记录回合数。 
deque <int> q;
vector <int> a;
int head=1,tail=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	ans=n;
	memset(f,0,sizeof(f));
	memset(e,0,sizeof(e));
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
		tail++;
	}
	for (int i=1;i<=n;i++)
	{
		while(head<tail)
		{
			if (f[a[head]])
			{
				while (q.front()!=a[head]) q.pop_front();
				q.pop_front();
				f[a[head]]=0;
				f[a[head]]++;
				q.push_front(a[head]);
			} 
			else
			{
				q.push_back(a[head]);
				f[a[head]]++;
			}
			head++;
		}
		while (!q.empty())
		{
			e[q.front()]++;
			for (int i=1;i<=m;i++) cout<<e[i]<<" ";
			q.pop_front();
		}
		ans++;
		head=ans; 
	}	
	for (int i=1;i<=m;i++)
	{
		if (!e[i]) continue;
		else cout<<e[i]<<" ";
	} 
	return 0;
}
