#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n, m;
int a[maxn];
int ans[maxn];
int ats[maxn];
vector <int> s;
int main (){
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		s.clear();
		for (int j = 1; j <= m; j++) ats[j] = 0;
		for (int j = i; j <= n; j++){
			if (ats[a[j]] != 0){
				int ps = ats[a[j]];
				while (s.size() > ps){
					ats[s[s.size() - 1]] = 0;
					s.pop_back ();
				}
				continue;
			}
			s.push_back (a[j]);
			ats[a[j]] = s.size();
		}
		for (int j : s){
			ans[j]++;
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	cout << flush;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
//100+100+65+48=313 PTS.
