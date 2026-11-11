#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int n;
long long d;
long long x[maxn];
vector <int> s[maxn];
int b[5005][5005];
int dis[5005][5005];
void dfs (int step, int st, int cnt){
	if (step > n){
		return;
	}
	for (int i : s[step]){
		cnt++;
		if (cnt == dis[st][i]){
			b[st][i]++;
		}
		else if (cnt < dis[st][i]){
			b[st][i] = 1;
			dis[st][i] = cnt;
		}
		else{
			continue;
		}
		dfs (i, st, cnt + 1);
	}
}
void sol (){
	cin >> n >> d;
	for (int i = 1; i <= n; i++){
		cin >> x[i];
		s[i].clear ();
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) b[i][j] = 0, dis[i][j] = 0x3f3f3f3f;
	}
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (abs (x[i] - x[j]) <= d){
				s[i].push_back (j);
			}
			else{
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		dfs (i, i, 0);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (b[i][j] == 2){
				ans++;
			}
//			cout << i << " -> " << j << " | " << dis[i][j] << " " << b[i][j] << endl;
		}
	}
	cout << ans << "\n";
}
int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	int c, T;
	cin >> c >> T;
	while (T--){
		sol ();
	}
	cout << flush;
	fclose (stdin);
	fclose (stdout);
	return 0;
}

