#include<iostream>
#include<vector>
#include<map>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int T;
const long long N = 2e5*1e9;
int n;
char L[N];

void solve() {
	cin >> n;
	vector<pair<long long, char> > L;
	for(int i=0; i<n; i++){
		long long a;
		char c;
		cin >> a >> c;
		L.push_back({a, c});
	}
	long long l=0, r=L.size()-1;
	long long ans=0;
	while(l <= r){
		long long al=L[l].first;
		char cl=L[l].second;
		long long ar=L[r].first;
		char cr=L[r].second;
		if(cl == cr){
			if(al > ar){
				L[l].first = al - ar;
				--r;
			}else if(al < ar){
				L[r].first = ar - al;
				++l;
			}else {
				++l, --r;
			}
		}else {
			if(al > ar){
				L[l].first = al-ar;
				ans += ar;
				--r;
			}else if(al < ar){
				L[r].first = ar-al;
				ans += al;
				++l;
			}else {
				++l, --r;
				ans += al;
			}
		}
	}
	cout << ans << endl;
	return;
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	IOS;
	T = 1;
//	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}

