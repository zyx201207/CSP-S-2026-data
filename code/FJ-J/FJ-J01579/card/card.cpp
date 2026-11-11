#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
vector<int>b[300005];
bool vis[500005];
int cnt[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)vis[j]=true;
		queue<pair<int,int> >q;
		for(int j=1;j<=m;j++)
		{
			int t=1e13;
			for(int k=0;k<b[j].size();k++)
			{
				if(b[j][k]>i)break;
				t=b[j][k];
			}
			int t1=max(b[j][b[j].size()-1],i-1);
			if(t>=i&&t<t1)q.push(make_pair(t,t1-1));
		}
		while(!q.empty())
		{
			int x=q.front().first,y=q.front().second;
			q.pop();
			for(int j=x;j<=y;j++)
			{
				vis[j]=false;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(vis[j])cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}

