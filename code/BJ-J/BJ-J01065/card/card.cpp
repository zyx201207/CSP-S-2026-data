#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 7;
const int M = 3e5 + 7;

int n, m, a[N];
int h[M];
vector<int> G[N];
int rd[N], cnt[N];

void topsort()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		cnt[i] = 1;
		if(rd[i] == 0)
			q.push(i);
	}
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		
		for(auto v : G[u])
		{
			rd[v] --;
			cnt[v] += cnt[u];
			if(rd[v] == 0)
				q.push(v);
		}
	}
	return ;
}

int ans[N];

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	for(int i=n;i>=1;i--)
	{
		if(h[a[i]] == 0)
		{
			h[a[i]] = i;
			G[i].push_back(i+1);
			rd[i+1] ++;
			continue;
		}
		G[i].push_back(h[a[i]]);
		rd[h[a[i]]] ++;
	}
	
	topsort();
	
	for(int i=1;i<=n;i++)
	{
		int c = a[i];
		ans[c] = max(ans[c], cnt[i]);
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	
	return 0;
}
