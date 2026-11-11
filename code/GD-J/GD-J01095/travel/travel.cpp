#include <bits/stdc++.h>
#define scan(x) scanf("%lld", &x)
#define scan2(x, y) scanf("%lld%lld", &x, &y)
#define scan3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
using namespace std;
void scans(string& s) {s.clear();char in=getchar();while(in=='\n'||in==' '||in=='\t'||in=='\r')if(in==EOF)return;else in=getchar();while(in!='\n'&&in!=' '&&in!='\t'&&in!='\r' && in!=EOF)s+=in,in=getchar();}
using LL = long long;
using ll = long long;
#define filename "travel"
constexpr LL N = 1000100;
LL side[256];

LL c1, p1, c2, p2;
char h1, h2;
string s1, s2;

void solve() {
	side['A'] = side['B'] = side['C'] = 1;
	side['D'] = side['F'] = 2;
	scan(c1); scans(s1); scan(c2); scans(s2);
	h1 = s1.back(); h2 = s2.back();
	s1.pop_back(); sscanf(s1.c_str(), "%lld", &p1);
	s2.pop_back(); sscanf(s2.c_str(), "%lld", &p2);
	
	if(c1 == c2) {
		if(p1 == p2) {
			if(side[h1] == side[h2]) {
				if(h1 == 'F') h1 --;
				if(h2 == 'F') h2 --;
				if(abs(h1 - h2) == 1) puts("1111");
				else puts("1110");
			} else puts("1100");
		} else puts("1000");
	} else puts("0000");
}

int main() {
	freopen(filename  ".in", "r",  stdin);
	freopen(filename ".out", "w", stdout);
	
//	LL t; scan(t); while(t --)
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
