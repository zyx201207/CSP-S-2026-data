#include<bits/stdc++.h>
#define N 500005
using namespace std;

int n,m,a[N],pos[N],lst[N],nxt[N],siz[N],in[N];
vector<int> g[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	pos[a[n]]=lst[a[n]]=n;
	for (int i=n-1;i>=1;i--)
	{
		nxt[i]=pos[a[i]];
		if (!lst[a[i]]) lst[a[i]]=i;
		if (nxt[i]) g[i].push_back(nxt[i]),in[nxt[i]]++;
		else g[i].push_back(i+1),in[i+1]++;
		pos[a[i]]=i;
	}
	queue<int> q;
	for (int i=1;i<=n;i++)
	{
		if (!in[i])
			q.push(i);
	}
	while (!q.empty())
	{
		int u=q.front();
		q.pop(),siz[u]++;
		for (int v:g[u])
		{
			siz[v]+=siz[u];
			if (!--in[v])
				q.push(v);
		}
	}
	for (int i=1;i<=m;i++)
		cout << siz[lst[i]] << " \n"[i==m];
	return 0;
}
