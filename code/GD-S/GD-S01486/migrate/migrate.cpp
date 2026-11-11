#include <bits/stdc++.h>
using namespace std;
int n, d;
int x[2000006];
int mn[2000006];
struct abd{
	int dst, pos;
	bool operator< (const abd a) const{
		return pos + dst * n < a.pos + a.dst * n;
	}
};
map<abd, int> cnt;
int abc(int st){
	cnt.clear();
	memset(mn, 0x3f, sizeof(mn));
	int sum = 0;
	queue<abd> q;
	q.push({0, st});
	while(!q.empty()){
		abd u = q.front();
//		cout << u.dst << " " << u.pos << endl;
		cnt[u]++;
		q.pop();
		mn[u.pos] = min(mn[u.pos], u.dst);
		for (int i = u.pos + 1; x[i] - x[u.pos] <= d && i <= n; i++){
			q.push({u.dst + 1, i});
		}
	}
	for (int i = st + 1; i <= n; i++){
//		cout << mn[i] << " " << cnt[(abd){mn[i], i}] << " ";
		if (cnt[(abd){mn[i], i}] == 2){
			sum += 1;
		}
	}
//	cout << endl << endl;
	return sum;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> x[i];
		}
		int ans =0;
		for (int i = 1; i < n; i++){
			int tt = abc(i);
//			cout << tt << " ";
			ans += tt;
		}
		cout << ans << endl;
	}
	return 0;
}
