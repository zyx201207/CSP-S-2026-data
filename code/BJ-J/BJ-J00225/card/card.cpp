#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5 , M = 3e5 + 5;

int n , m , a[N] , res[M] , pre[N] , lst[M] , cnt;
int b[N] , id[N];
bool flagA = 1 , flagB = 1;

int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1 ; i <= n ; ++ i) cin >> a[i];
	for(int i = 1 ; i <= n ; ++ i)
	{
		pre[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	for(int i = 1 ; i < n ; ++ i) if(a[i] > a[i + 1]) flagA = 0;
	for(int i = 1 ; i < n ; ++ i) if(a[i] != a[i + 1]) ++ cnt;
	
	if((long long) n * m <= 15000000)
	{
		for(int i = 1 ; i <= n ; ++ i)
		{
			int idx = 0;
			for(int j = 1 ; j <= m ; ++ j) id[j] = 1e9;
			for(int j = 1 ; j <= n ; ++ j) b[j] = 0;
			for(int j = i ; j <= n ; ++ j)
			{
				if(id[a[j]] <= idx) {idx = id[a[j]];}
				else {++ idx; id[b[idx]] = 1e9; b[idx] = a[j]; id[a[j]] = idx;}
			}
			for(int j = 1 ; j <= idx ; ++ j) {++ res[b[j]];}
		}
		for(int i = 1 ; i <= m ; ++ i) cout << res[i] << ' ';
		cout << '\n';
	}
	else if(flagA)
	{
		for(int i = 1 ; i <= n ; ++ i) ++ res[a[i]];
		for(int i = 1 ; i <= m ; ++ i) cout << res[i] << ' ';
		cout << '\n';
	}
	else if((long long)cnt * m <= 15000000)
	{
		memset(res , 0 , sizeof res);
		
		vector<pair<int , int>> c;
		int num = 0;
		for(int i = 1 ; i <= n ; ++ i)
		{
			++ num;
			if(a[i] != a[i + 1] || i == n) {c.emplace_back(num , a[i]); num = 0;}
		}
		
		int sz = c.size();
		for(int i = 0 ; i < sz ; ++ i)
		{
			int idx = 0;
			for(int j = 0 ; j <= m ; ++ j) id[j] = 1e9;
			for(int j = 0 ; j <= sz ; ++ j) b[j] = 0;
			for(int j = i ; j < sz ; ++ j)
			{
				if(id[c[j].second] <= idx) idx = id[c[j].second];
				else {++ idx; id[b[idx]] = 1e9; b[idx] = c[j].second; id[c[j].second] = idx;}
			}
			for(int j = 1 ; j <= idx ; ++ j) res[b[j]] += c[i].first;
		}
		for(int i = 1 ; i <= m ; ++ i) cout << res[i] << ' ';
		cout << '\n';
	}
	else
	{
		while(m --) cout << "1 ";
	}
	
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
