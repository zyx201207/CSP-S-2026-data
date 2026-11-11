#include <bits/stdc++.h>
using namespace std;
#define two second
#define one first
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int, int> pii;//这个站在第one条线里，这个站站厅到这条线站台时间为two 
const int maxn = 501, maxm = 5e5 + 1;

void input(int &x){
	x = 0; char in = getchar();
	while(in < '0' || in > '9') in = getchar();
	while('0' <= in && in <= '9'){
		x = (x<<3) + (x<<1) + in - '0';
		in = getchar();
	}
}

int c, n, m, d, q;
int w[maxm];

ll dis[maxn][maxn];
vector<pii>v[maxm];

int main(){
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	input(c); input(n); input(m); input(d); input(q);
	for(int i = 1; i <= m; i++) input(w[i]);
	memset(dis, 63, sizeof(dis));
	for(int i = 1, k, a, t; i <= n; i++){
		input(k);
		for(int j = 1; j <= k; j++){
			input(a); input(t);
			v[a].push_back(mp(i, t));
		}dis[i][i] = 0;
	}
	for(int i = 1; i <= m; i++)
		for(int j = 0; j < v[i].size(); j++)
			for(int k = 0; k < v[i].size(); k++)
				dis[v[i][j].one][v[i][k].one] = min(dis[v[i][j].one][v[i][k].one], (ll)(v[i][j].two + v[i][k].two));

	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	ll ans;
	for(int x, y; q; q--){
		input(x); input(y);
		ans = dis[0][0];
		for(int i = 0; i < v[x].size(); i++)
			for(int j = 0; j < v[y].size(); j++)
					ans = min(ans, dis[v[x][i].one][v[y][j].one] + v[x][i].two + v[y][j].two);
		printf("%lld\n", ans + w[x] + w[y]);
	}return 0;
}
