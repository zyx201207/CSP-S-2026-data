#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500000;
struct sta{
	int t_g, d = 0;
	int l[20][2];
}stas[MAXN+5];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> stas[i].t_g;
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		while(k){
			int s, t;
			cin >> s >> t;
			stas[s].d++;
			stas[s].l[stas[s].d][0] = i;
			stas[s].l[stas[s].d][1] = t;
			k--;
		}
	}
	while(q){
		int s1, s2;
		cin >> s1 >> s2;
		long long ans = stas[s1].t_g + stas[s2].t_g + stas[s1].l[1][1] + stas[s2].l[1][1];
		cout << ans << endl;
		q--;		
	}
	return 0;
}
