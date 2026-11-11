#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
#define __low lower_bound
#define __upp upper_bound
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5+5;

int n;
ll a[N], sum, mid, ans;
char c[N];

struct pp{
	ll x, op;
	char c;
	bool operator < (const pp &a) const{
		return x < a.x;
	}
};
vector<pp> ve;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		sum += a[i];
		a[i] += a[i-1];
	}
	ans = mid = sum/2;
	bool ok = 0;
	for(int i = 1; i <= n; i++){
		if(!ok){
			if(a[i] > mid) {
				ok = 1;
				ve.pb({a[i-1], 0, c[i]});
				ve.pb({sum-a[i], 1, c[i]});
			} else{
				ve.pb({a[i-1], 0, c[i]});
			}
		} else{
			ve.pb({sum-a[i], 1, c[i]});
		}
	}
	ve.pb({mid, 0, '#'});
	sort(ve.begin(), ve.end());
	
	char nowa = '#', nowb = '#';
	ll last = 0;
	for(auto x : ve){
		if(x.x > mid) break;
		if(nowa == nowb) ans -= x.x - last;
		if(x.op) nowb = x.c;
		else nowa = x.c;
		last = x.x;
	}
	cout << ans << "\n";
	
	return 0;
}
