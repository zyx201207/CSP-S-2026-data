#include<bits/stdc++.h>
using namespace std;

int vis[300005], cnt[300005], n, m, a[500005];
vector<int> vec;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis, 0, sizeof vis);
		vec.clear();
		for(int j=i;j<=n;j++)
		{ // dachu a[j]
			if(vis[a[j]]) // youle
			{
				vec.erase(vec.begin()+vis[a[j]], vec.end());
				vis[a[j]]=j;
			}
			vec.push_back(a[j]);
		}
		for(int j=0;j<m;j++)
		{
			if(vis[j+1])
				cnt[j+1]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	
}
