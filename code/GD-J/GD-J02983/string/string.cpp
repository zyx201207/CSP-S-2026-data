#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<char> c(n);
	for(int i = 0; i < n; i ++) cin >> a[i] >> c[i];
//	// debug
//	for(int i = 0; i < n; i ++) cout << a[i] << ' ' << c[i] << endl;
	
	int itl = 0, itr = n - 1, nl = 0, nr = 0;
	ll ans = 0;
	while(itl < itr){
//		// debug
//		cout << itl << ' ' << itr << ' ' << nl << ' ' << nr << ' ' << ans << endl;
//		
		if(a[itl] - nl == a[itr] - nr){
			if(c[itl] != c[itr]){
				ans += a[itl] - nl;
			}
			itl ++, itr --;
			nl = 0, nr = 0;
//			// debug
//			cout << 1 << endl;
		}
		else if(a[itl] - nl < a[itr] - nr){
			if(c[itl] != c[itr]){
				ans += a[itl] - nl;
			}
			nr += a[itl] - nl;
			itl ++;
			nl = 0;
//			// debug
//			cout << 2 << endl;
		}
		else{
			if(c[itl] != c[itr]){
				ans += a[itr] - nr;
			}
			nl += a[itr] - nr;
			itr --;
			nr = 0;
//			// debug
//			cout << 3 << endl;
		}
	}
	cout << ans << '\n';
}
