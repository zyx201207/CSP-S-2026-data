#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> a;
ll n ,m ,ans = -99999;
int max(ll a, ll b) {
	return a >= b ? a : b;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for( int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	if ( n == 1 ){
		cout << 1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a.begin() ,a.end());
	for(int s = n / 2 ; s >= 0 ; s--){
//		cout <<" s:"<<s<<" ";
		int res = m;//还要加的 
		int cnt = 0;
		vector<ll> t = a; 
		ll cos = 1;
		ll i = s;
		bool flag = 0;
		while (i <= n && res > 0) {
//			cout << i <<" ";
			if ( ( t[i + 1] - t[i] ) * cos > res){flag = 1; break;} 
			while (t[i] == t[i + 1]) {
				cos ++;
				i ++;
			}
			res -= cos;
			t[i] ++; 
//			cout <<"add:"<<i<<"  cos:" << cos << "  res:" << res << "\n";
		}
		if (flag == 1) continue;
		while (t[i] == t[i + 1]) cos ++, i ++;
//		cout <<endl;
//		for (auto i : t) cout << i <<" ";  
//		for (int i =s ; t[i] == t[i + 1]; i++){
//			cnt ++;
//		}
//		cout << "cos:" << cos << "\n";
		ans = max (ans ,cos);
//		cout << "ans:" << ans << "\n";
	}
	cout << ans;
	//for (auto i : a) cout << i;                                                                                                                                                                                                                                                                                                                                                                                                                 i;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
