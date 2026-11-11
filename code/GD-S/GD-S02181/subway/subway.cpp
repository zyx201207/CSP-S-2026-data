#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL const MAXN = 1e6 + 10;

LL n, m, d, q;
LL s, t;
LL w[MAXP];
vector<pair<LL, LL>> waiz[MAXN];
vector<pair<LL, LL>> incl[MAXN];
int main()
{
	cin >> n >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)cin >> w[i];
	
	
	LL k, x;
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> x >> t; waiz[x].push_back({i, t});
			incl[i].push_back({x, t});
		}
	}
	
	
	while(q--){
		cin >> s >> t;
		
	}
	
	
	
	
	
	
	return 0;
}
