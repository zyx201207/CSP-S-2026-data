#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
map<int,long long> x;
map<int,long long> y;
stack<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;int i,j;
	for(i=1;i<=n;++i)
	cin>>a[i];
	for(j=1;j<=n;j++)
	{
		for(i=j;i<=n;++i)
		{
			if(x[a[i]]==1)
			{
				while(q.top()!=a[i])
				{
					--x[q.top()];
					q.pop();
				}
				continue;
			}
			q.push(a[i]);
			++x[a[i]];
		}
		while(!q.empty())
		{
			++y[q.top()];
			--x[q.top()];
			q.pop();
		}
	}
	for(i=1;i<=m;++i)
	cout<<y[i]<<' ';
	return 0;
}