#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	priority_queue<int> a;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a.push(x);
	}
	int ans=-1;
	for(int i=1;i<n;i++)
	{
		int ans1;
		for(int j=1;j<=m;j++)
		{
			if(j==1)
			{
				ans1==a.top();
				a.pop();
				continue;
			}
			int u=a.top();
			a.pop();
			a.push(u);
			ans1 &= u;
			if(j==m)
			{
				if(ans1>ans)
				{
					ans=ans1;
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
