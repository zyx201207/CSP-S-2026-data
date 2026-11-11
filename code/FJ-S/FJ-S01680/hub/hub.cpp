#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
struct Edges{
	int u, v;
};

int qread() {
	auto ch = getchar();
	int res = 0;
	while (isdigit(ch)){
		res = (res<<1) + (res<<3) + (ch-'0');
		ch = getchar();
	}
	return res;
}

void solve() {
	int n = qread(), k = qread();
	vector<Edges> gr(n);
	for (int i = 1; i < n; i++) {
		int u = qread(), v = qread();
		gr[i] = {u, v};
	}
	cout <<k-1<<"\n";
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c = qread(), t = qread();
	for (int i = 0; i < t; i++) {
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

