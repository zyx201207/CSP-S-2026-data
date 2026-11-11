#include <bits/stdc++.h>
#define scan(x) scanf("%lld", &x)
#define scan2(x, y) scanf("%lld%lld", &x, &y)
#define scan3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
using namespace std;
void scans(string& s) {s.clear();char in=getchar();while(in=='\n'||in==' '||in=='\t'||in=='\r')if(in==EOF)return;else in=getchar();while(in!='\n'&&in!=' '&&in!='\t'&&in!='\r' && in!=EOF)s+=in,in=getchar();}
using LL = long long;
using ll = long long;
#define filename "string"
constexpr LL N = 1000100;

LL n, cnt;
string s;
vector <pair <LL, char>> vt;

void solve() {
	scan(n);
	for(LL i = 1, x; i <= n; i ++) {
		scan(x);
		in:char c = getchar(); if(c == ' ') goto in;
		vt.push_back({x, c});
	}
	for(LL i = 0, j = vt.size() - 1; i < j; i ++, j --) {
//		printf("i=%lld j=%lld vt[i]={%lld,%c} vt[j]={%lld,%c}\n", i, j, vt[i].first, vt[i].second, vt[j].first, vt[j].second);
		if(vt[i] == vt[j]) continue;
		if(vt[i].second == vt[j].second) {
			if(vt[i].first > vt[j].first) vt[i --].first -= vt[j].first;
			else if(vt[i].first < vt[j].first) vt[j ++].first -= vt[i].first;
		} else {
			cnt += min(vt[i].first, vt[j].first);
			if(vt[i].first < vt[j].first) vt[j ++].first -= vt[i].first;
			else if(vt[i].first > vt[j].first) vt[i --].first -= vt[j].first;
		}
	}
	printf("%lld\n", cnt);
}

int main() {
	freopen(filename  ".in", "r",  stdin);
	freopen(filename ".out", "w", stdout);

//	LL t; scan(t); while(t --)
	solve();

	fclose(stdout);
	fclose(stdin);
	return 0;
}

