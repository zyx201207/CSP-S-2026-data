#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 1;
const int inf = 0x3f3f3f3f;

signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c , t;
	cin >> c >> t;
	if(c >= 11 && c <= 14){
		while(t --){
			vector<int> x;
			int n , d;
			cin >> n >> d;
			for(int i = 1 ; i <= n ; i ++){
				int t;
				cin >> t;
				x.push_back(t);
			}
			if(c >= 11 && c <= 12){
				int num = x[1] - x[0];
				if(d <= 2 * num){
					cout << 0;
				}else{
					cout << (n - 3) * (n - 4) / 2;
				}
			}else if(c >= 13 && c <= 14){
				cout << (n - 1) * (n - 2) / 2;
			}
			cout << '\n';
		}
	} 
	return 0;
}
