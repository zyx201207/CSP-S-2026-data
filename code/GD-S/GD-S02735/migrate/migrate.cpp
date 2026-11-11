#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t --){
//		// debug
//		cout << "t" << t << endl;
		int n;
		ll d;
		cin >> n >> d;
		vector<ll> x(n);
		for(auto &v : x) cin >> v;
		
		vector<int> l;
		for(int i = 0; i + 3 < n; i ++) if(x[i + 3] - x[i] > d && x[i + 3] - x[i + 1] <= d && x[i + 2] - x[i] <= d){
			l.emplace_back(i);
		}
		
		int ans = 0;
		for(auto &i : l){
			ans ++;
//			// debug
//			cout << endl << i << endl;
			int j, l = 0;
			for(j = i - 1; j >= 0; j --){
				if(x[i + 3] - x[j] > d && x[i + 2] - x[j] <= d){
					l ++;
//					// debug
//					cout << ' ' << j << endl;
				}
				else{
					break;
				}
			}
			bool jump = 0;
			for(; j >= 0; j --){
				if(x[j + 1] - x[j] <= d && x[j + 2] - x[j] > d){
					l ++;
					jump = 1;
				}
				else if(x[j + 2] - x[j] <= d && x[j + 3] - x[j] > d && jump){
					l ++;
					jump = 0;
				}
				else{
					break;
				}
			}
			
			int r = 0;
			for(j = i + 4; j < n; j ++){
				if(x[j] - x[i + 1] <= d && x[j] - x[i] > d){
					r ++;
//					// debug
//					cout << j << endl;
				}
				else{
					break;
				}
			}
			jump = 0;
			for(; j < n; j ++){
				if(x[j] - x[j - 1] <= d && x[j] - x[j - 2] > d){
					r ++;
					jump = 1;
				}
				else if(x[j] - x[j - 2] <= d && x[j] - x[j - 3] > d && jump){
					r ++;
					jump = 0;
				}
				else{
					break;
				}
			}
			l ++, r ++;
			ans += l * r - 1;
//			// debug
//			cout << i << ' ' << l << ' ' << r << endl;
		}
		
		cout << ans << '\n';
	}
}
