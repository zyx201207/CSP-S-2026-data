#include<bits/stdc++.h>
using namespace std;
int a[500010];
int ans[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		map<int,int>mp;
		queue<int>q;
		for(int j=i;j<=n;j++)
		{
			if(mp[a[j]]!=0)
			{
				int s=q.front();
				while(q.front()==a[j])
				{
					q.push(q.front());
					q.pop();
				}
				while(q.front()==s)
				{
					mp[q.front()]--;
					q.pop();
				}
				if(s==a[j])
				{
					while(!q.empty())mp[q.front()]--,q.pop();
				}
				mp[q.front()]--;
				q.pop();
			}
			q.push(a[j]);
			mp[a[j]]++;
		}
		for(int j=1;j<=m;j++)
		{
			if(mp[j])ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
