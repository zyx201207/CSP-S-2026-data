#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 2, maxm = 5e5 + 2;
vector<int> s[maxn], t[maxn];
int w[maxm], k[maxn];
int g[2][maxm];
int c, n, m, d, q;
int flag1;
int ans;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		if(k[i] > 2)
			flag1 = 1;
		for(int j = 1; j <= k[i]; j++){
			int x, y;
			cin >> x >> y;
			s[i].push_back(x);
			t[i].push_back(y);
		}
	}
	if(n <= 2){
		while(q--){
			ans = 0x3f3f3f3f;
			int x, y;
			cin >> x >> y;
			bool a = 0, b = 0;
			for(int i = 0; i < k[1]; i++){
				if(s[1][i] == x) 
					a = 1;
				if(s[1][i] == y)
					b = 1;
			}
			if(a == b)
				cout << w[x] + w[y] << '\n';
			else{
				for(int i = 0; i < k[1]; i++)
					g[0][s[1][i]] = t[1][i];
				for(int i = 0; i < k[2]; i++)
					g[1][s[2][i]] = t[2][i];
				for(int i = 1; i <= m; i++)
					if(g[0][i] && g[1][i])
						ans = min(ans, g[0][i] + g[1][i]);
				cout << ans + w[x] + w[y] << '\n';
			}	
		}
	}
	return 0;
}
//Oct31==Dec25?

