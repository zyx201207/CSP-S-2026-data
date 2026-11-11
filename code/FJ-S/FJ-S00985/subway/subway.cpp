#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define int ll
const int N = 5e5 + 10;
int c, n, m, d, q, t[N], ans, k[N];
struct node{
	int a, t;
}s[5010][5010];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < m;i ++){
		cin >> t[i];
	}
	for(int i = 0;i < n;i ++){
		cin >> k[i];
		for(int j = 0;j < k[i];j ++){
			cin >> s[i][j].a >> s[i][j].t;
		}
	}
	while(q --){
		ans = 0;
		int x, y;
		cin >> x >> y;
		ans += t[x - 1];
		ans += t[y - 1];
		if(abs(x - y) == 1){
			bool flagx = 0;
			bool flagy = 0;
			for(int i = 0;i < n;i ++){
				flagx = 0;
				flagy = 0;
				for(int j = 0;j < k[i];j ++){
					if(s[i][j].a == x){
						flagx = 1;
						ans += s[i][j].t ;
					}
					if(s[i][j].a == y){
						flagy = 1;
						ans += s[i][j].t ;
					}
				}
				if(flagx && flagy){
					cout << ans << endl;
				}else{
					ans = 0;
				}
			}
		}else{
			int mid = (x + y) / 2;
			bool flagx = 0;
			bool flagy = 0;
			int xx, yy;
			for(int i = 0;i < n;i ++){
				flagx = 0;
				flagy = 0;
				for(int j = 0;j < k[i];j ++){
					if(s[i][j].a == x){
						flagx = 1;
						xx = s[i][j].t ;
					}
					if(s[i][j].a == mid){
						flagy = 1;
						yy = s[i][j].t ;
					}
				}
				if(flagx && flagy){
					ans += xx;
					ans += yy;
					break;
				}
			}
			flagx = 0;
			flagy = 0;
			for(int i = 0;i < n;i ++){
				flagx = 0;
				flagy = 0;
				for(int j = 0;j < k[i];j ++){
					if(s[i][j].a == mid){
						flagx = 1;
						xx = s[i][j].t ;
					}
					if(s[i][j].a == y){
						flagy = 1;
						yy = s[i][j].t ;
					}
				}
				if(flagx && flagy){
					cout << ans + xx + yy << endl;
				}
			}
		}
	}
	return 0;
}
