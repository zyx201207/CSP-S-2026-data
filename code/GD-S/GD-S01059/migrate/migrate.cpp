#include<bits/stdc++.h>
#define psb push_back

using namespace std;

typedef long long ll;
const int N=5010;
int n; ll d,X[N];
vector<int> G[N];
int dis[N], cnt[N]; int ans;

void bfs(int st)
{
	for (int i=1;i<=n;i++) dis[i]=-1, cnt[i]=0;
	dis[st]=0, cnt[st]=1; queue<int> q; q.push(st);
	while (q.size())
	{
		int u=q.front(); q.pop();
		for (int v : G[u])
		{
			if (dis[v]==-1) dis[v]=dis[u]+1, cnt[v]=cnt[u], q.push(v);
			else if (dis[v]==dis[u]+1) cnt[v]=min(cnt[v]+cnt[u],3); 
		} 
	}
	for (int i=1;i<=n;i++) 
	{
		ans+=(cnt[i]==2);
		//if (cnt[i]==2) {cout << st << " " << i << " " << dis[i] << "\n"; }
	}
}

void solve()
{
	cin >> n >> d;
	for (int i=1;i<=n;i++) cin >> X[i];
	for (int i=1;i<=n;i++) G[i].clear();
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (X[j]-X[i]<=d) G[i].psb(j);
	ans=0; for (int s=1;s<=n;s++) bfs(s); 
	cout << ans << "\n";
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,T; cin >> c >> T;
	while (T--) solve(); 	
	
	return 0;
}

/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
5 3
-2 -1 0 1 2

0 1
6 3
0 1 2 3 4 7

*/
