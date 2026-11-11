#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

const int N = 2e6 + 10, inf = 1e9;
int c, t, n; ll d, x[N], f[N], g[N], ans;
vector<int> v; bool sub1, sub2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d; ans = 0; sub1 = 1;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
			if(i > 1) sub1 &= (x[i] - x[i-1] == x[2] - x[1]);
		}
		sub2 = (x[n] - x[1] <= 10*d);
		if(sub1){
			int lst, p = 1;
			v.clear();
			v.push_back(1);
			v.push_back(1+1);
			while(1){
				lst = p;
				p = upper_bound(x + 1, x + 1 + n, x[p]+d) - x - 1;
				if(p == lst) break;
				v.push_back(p+1);
			}
			f[1] = g[1] = 1; g[1-1] = 0;
			for(int j = 1+1; j <= n; j++) f[j] = 0, g[j] = 1;
			for(int j = 2; j < v.size(); j++){
				int p1 = v[j-2];
				for(int p2 = v[j-1]; p2 < v[j]; p2++){
					while(p1 < v[j-1]-1 && x[p1] < x[p2]-d) p1++;
					f[p2] = min(3ll, g[v[j-1]-1] - g[p1-1]);
				}
				for(int p2 = v[j-1]; p2 < v[j]; p2++){
					g[p2] = g[p2-1] + f[p2];
				}
			}
			for(int j = 1; j <= n; j++) ans += (f[j] == 2)*(n-j+1);
		}
		else if(n <= 5000 || sub2){
			for(int i = 1; i <= n; i++){
				int lst, p = i;
				v.clear();
				v.push_back(i);
				v.push_back(i+1);
				while(1){
					lst = p;
					p = upper_bound(x + 1, x + 1 + n, x[p]+d) - x - 1;
					if(p == lst) break;
					v.push_back(p+1);
				}
				f[i] = g[i] = 1; g[i-1] = 0;
				for(int j = i+1; j <= n; j++) f[j] = 0, g[j] = 1;
				if(v.size() >= 3){
					int l1, r1, l2, r2;
					for(int j = 2; j < v.size(); j++){
						l1 = v[j-2], r1 = v[j-1]-1;
						l2 = v[j-1], r2 = v[j]-1;
						int p1 = l1;
						for(int p2 = l2; p2 <= r2; p2++){
							while(p1 < r1 && x[p1] < x[p2]-d) p1++;
							f[p2] = min(3ll, g[r1] - g[p1-1]);
						}
						for(int p2 = l2; p2 <= r2; p2++){
							g[p2] = g[p2-1] + f[p2];
						}
					}
				}
//				for(int j = i; j <= n; j++) cout << f[j] << ' ';
//				cout << '\n';
				for(int j = i; j <= n; j++) ans += (f[j] == 2);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
