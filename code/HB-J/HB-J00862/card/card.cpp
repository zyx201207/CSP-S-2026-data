#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[100005];
bool b[100005];
stack<int> q;
void sol(int st)
{
	for(int i=st;i<=n;i++)
	{
		if(b[a[i]]==false)
		{
			b[a[i]]=1;
			q.push(a[i]);
		}
		else
		{
			while(q.top()!=a[i])
			{
				b[q.top()]=false;
				q.pop();
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int _=1;_<=n;_++)
	{
		for(int i=1;i<=m;i++)
		{
			b[i]=false;
		}
		sol(_);
		for(int i=1;i<=m;i++)
		{
			if(b[i])ans[i]++;
		}
	}
	for(int i=1;i<=m;++i)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
