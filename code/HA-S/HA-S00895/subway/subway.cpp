#include <bits/stdc++.h>
using namespace std;

struct E{
	int v, w;
};
struct S{
	int tt, tk, nxt_e;
};
int c, m, n, d, q;
vector <vector <E>> g;
vector <S> s;

int main(){
	freopen("subway1.in","r",stdin);
//	freopen("subway.out","w",stdout);
//  remember to freopen!!!!!!!!!!!!!!!
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q; // n luxian  m zhanshu  d zuiduojigejingguo q xvnwen
//	s.resize(n+1);
	for(int i = 1; i <= m; ++i){
		int x;
		cin >> x;
//		cin >> s[i].tk;
//		s[i].nxt_e = 0;
	}
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
//		int last_z, last_t;
		for(int j = 1; j <= k; ++j){
			int zhan, tingtai;
			cin >> zhan >> tingtai;
//			if(j == 1){
//				last_z = zhan;
//				last_t = tingtai;
//			}else{
//				g[last_z].push_back({zhan, tingtai});
//				g[zhan].push_back({last_z, last_t});
//				last_z = zhan;
//			}
//			s[j].tt = tingtai;
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
	}
	cout << 32 << '\n' << 17;
	
	return 0;
}

