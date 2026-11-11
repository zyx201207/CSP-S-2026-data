#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300020],a[500020],last[300020];
stack<int>q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(last[a[j]])
			{
				while(q.top()!=a[j] and !q.empty())
				{
					last[q.top()]=0;
					q.pop();
				}
			}
			else
			{
				q.push(a[j]);
				last[a[j]]=1;
			}
		}
		while(!q.empty())
		{
			ans[q.top()]++;
			last[q.top()]=0;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}

