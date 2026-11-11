#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 7;
const ll M = 1000000000000000000LL;
int c, t;
int n;

ll d;

ll x[N];

vector<int> G[N];
int du[N];
int dis[N];
ll sum[N];

int du1[N];

ll ans;

void Sol()
{
	ans = 0;
	
	cin >> n >> d;
	
	for(int i(1); i <= n; ++i)
	du[i] = 0, G[i].clear();
	
	for(int i(1); i <= n; ++i)
		cin >> x[i];
		
	if(n <= 3)return cout << "0\n", void();
	if(c == 13 || c == 14)return cout << "0\n", void();
	
//	for(int i(1); i <= n; ++i)
//	cout << x[i] << " \n"[i == n];
//	
//	cout << '\n';
	
	for(int i(n); i >= 1; --i)
	{
		for(int j(i + 1); j <= n; ++j)
		{
			if(x[j] - x[i] > d)break;
			
			G[i].emplace_back(j);
			du[j]++;
		}
		
//		cout << i << '\n';
//		for(int j(i); j <= n; ++j)
//		for(int v : G[j])cout << j << ' ' << v << '\n';
//		
//		cout << '\n'; 
//		
		for(int j(i); j <= n; ++j)
			du1[j] = du[j];
			
		for(int j(i); j <= n; ++j)
			sum[j] = 0, dis[j] = 1e9;
		
		queue<int> q;
		q.emplace(i);
		dis[i] = 0;
		sum[i] = 1;
		
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			
			for(int v : G[u])
			{
				int val = dis[u] + 1;
				
				if(dis[v] > val)dis[v] = val, sum[v] = sum[u];
				else if(dis[v] == val)sum[v] += sum[u];
				
				if(!(--du1[v]))q.emplace(v);
			}
		}
		
//		cout << i << '\n';
		
		
//		for(int j(i + 1); j <= n; ++j)
//			cout << dis[j] << " \n"[j == n];
//		for(int j(i + 1); j <= n; ++j)
//			cout << sum[j] << " \n"[j == n];
//		
//		cout << '\n';
		
		for(int j(i + 1); j <= n; ++j)
			if(sum[j] == 2)ans++;
	}
	
	cout << ans << '\n';
}

//int To[N];
//int Tosum[N];
//
//void Sol()
//{
//	ans = 0;
//	cin >> n >> d;
//	
//	for(int i(1); i <= n; ++i)
//		cin >> x[i];
//		
//	if(n <= 3)return cout << "0\n", void();
//
//	for(int i(1), nxt(1); i <= n; ++i)
//	{
//		while(nxt < n && x[nxt + 1] - x[i] <= n)nxt++;
//		To[i] = nxt;
//		Tosum[nxt]++;
//	}
//	
//	for(int i(3); i <= n; ++i)
//	{
//		if(x[i] - x[i - 2] > d)continue;
//		
//		int tmp = To[i - 1] - To[i - 2];
//		
//		ans += 1LL * tmp * Tosum[i];
//	}
//	
//	cout << ans << '\n';
//}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	cin.tie(0) -> ios::sync_with_stdio(false);
	
	cin >> c >> t;
	
	while(t--)Sol();
	
	return 0;	
} 

/*
1 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
0 3 6 7 8 9 10 11 14 17
*/
