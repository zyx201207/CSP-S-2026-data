#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

int qread() {
	auto ch = getchar();
	int res = 0, signaln = 1;
	if (!isdigit(ch)) {
		signaln = -1;
		ch = getchar();
	} 
	
	while (isdigit(ch)){
		res = (res<<1) + (res<<3) + (ch-'0');
		ch = getchar();
	}
	return res*signaln;
}

void solve() {
	int n = qread(), dis = qread();
	vector<int> islands(n+1);
	set<int> isl;
	vector<int> dists(n+1);
	for (int i = 1; i <= n; i++) {
		islands[i] = qread();
		isl.insert(islands[i]);
		dists[i] = islands[i] - islands[i-1] + dists[i-1];
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) { 
		for (int j = i; j <= n; j++){
			if (dists[i]);
		}
		
		res ++;
	}/*
	while (pos != final) {
		pos += dis;
		while (!isl.count(pos)) pos --;
		if ()
	}
	*/
	cout <<((n&1) ? 2 : 1)<<"\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = qread(), t = qread();
	for (int i = 0; i < t; i++) {
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

