#include <bits/stdc++.h>
using namespace std;

const int N=2*1000*1000+10;
int a[N];
vector <int> adj[N];

int dp[N],cnt[N];

int n,d;
bool vis[N];
void bfs(int st){
	queue <int> q;
	
	q.push(st);
	vis[st]=true;
	
	while (!q.empty()){
	
		int u=q.front();
		q.pop();
		vis[u]=true;
		
		for (int v:adj[u]){
			if (vis[v])continue;
			
			dp[v]=dp[u]+1;
			cnt[v]++;
		}
	}
}


int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);

	int c,t;
	cin >>c>>t;

	while (t--)
	{
		cin >>n>>d;

		for (int i=1; i<=n; i++)
		{
			cin >>a[i];
		}

		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				if (i==j)continue;
				if (abs(a[i]-a[j])<=d)adj[i].emplace_back(j);
			}
		}
		
		long long ans=0;
		for (int i=1;i<=n;i++){
			memset(dp,0x3f,sizeof(dp));
			memset(cnt,0,sizeof(cnt));
		
			bfs(i);
			
		
			for (int j=1;j<=n;j++)
				if (i!=j&&cnt[i]==2)ans++;
		}
		
		cout <<ans<<'\n';
	}

	return 0;
}
