#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		deque<int> q;
		bool f[300010]={0};
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]])
			{
				while(q.back()!=a[j])
				{
					f[q.back()]=0;
					q.pop_back();
				}
			}
			else
			{
				q.push_back(a[j]);
				f[a[j]]=1;
			}
		}
		while(!q.empty())
		{
			ans[q.front()]++;
			q.pop_front();
		}
	}
	ans[a[n]]++;
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
