#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
void file() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
} 
int ans_c=0,n,m,a[N];
vector<int> p;
void solve() {
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	// for(int i=1;i<=n;i++) {
		// for(int c=30;c>=0;c--)
			// cout << ((a[i]>>c)&1);
		// cout << '\n';
	// }
	for(int c=0;c<=30;c++) {
		int cnt = 0;
		for(int i=1;i<=n;i++) {
			if(a[i]&(1<<c)) cnt++;
		}
		if(cnt>=m) ans_c = c;
	}
	for(int i=1;i<=n;i++) {
		if(a[i]&(1<<ans_c)) p.push_back(a[i]);
	}
	for(int c=ans_c-1;c>=0;c--) {
		int cnt = 0;
		for(int i=0;i<p.size();i++) {
			if(p[i]&(1<<c)) cnt++;
		}
		if(cnt<m) continue; // 此位一定为0
		for(int i=0;i<p.size();i++) {
			if(!(p[i]&(1<<c))) p.erase(p.begin()+i);
		}
		// for(auto i : p ) cout << i << ' ';
		// cout << '\n';
	}
	int aans=p[0];
	for(int i=1;i<p.size()&&i<m;i++) aans = (aans&p[i]);
	cout << aans << '\n';
}
int main() {
	file();
	int t=1;
	// cin >> t;
	while(t--) solve();
}
