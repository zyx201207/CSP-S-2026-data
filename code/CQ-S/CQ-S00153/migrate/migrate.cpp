#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6;
int c,t;
int n;
long long d,a[N+5];
vector<long long>g;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		long long ans = 0;
		cin >> n >> d;
		long long L = d+1,R = 2*d-1;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++){
			while (g.size()) g.pop_back();
			int l = lower_bound(a+1, a+n+1, a[i]+L)-a;
			int r = lower_bound(a+1, a+n+1, a[i]+R)-a;
			if (a[i+1]-a[i] > d) continue;
			if (a[r] < a[i]+L)
				continue;
			if (a[l] < a[i]+L) l++;
			if (l-i < 3) continue;
			for (int j = i+1; j <= l-1; j++)
				g.push_back(a[j]-a[i]);
//			cout << a[i] << ":";
			for (int j = i+1; j <= l-1; j++){
//				cout << a[j]-a[i] << " ";
			}
//			cout << "\n"; 
			long long tt = g.size();
			for (int j = l; j <= r; j++){
				long long x = a[j]-a[i]-d;
				long long h = lower_bound(g.begin(),g.end(),x)-g.begin();
				h = tt-h;
				if (h == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
