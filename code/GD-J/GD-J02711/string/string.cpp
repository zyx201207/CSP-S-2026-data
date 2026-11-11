#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
const ll N = 2e5 + 10;
ll a[N];
char c[N];
string s;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	for(ll i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	for(ll i = 1; i <= n; i++)
		for(ll j = 1; j <= a[i]; j++)
			if(s.size() >= 1e16) exit(1);
			else s += c[i];
	ll ans = 0;
	for(ll i = 0; i < floor(s.size() / 2.0); i++)
		if(s[i] != s[s.size() - 1 - i])
			ans++;
	cout << ans << '\n';
	
	return 0;
} 
/* 
#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
const ll N = 2e5 + 10;
ll a[N];
char c[N];
ll n;
ll size_;
ll idx[N]; // a[i] <= c[i] < a[i + 1]
ll rvs_idx[N];
ll ans;
int main(){
	freopen("string5.in", "r", stdin);
	freopen("string5.out", "w", stdout);
	cin >> n;
	for(ll i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	for(ll i = 1; i <= n; i++)
		size_ += a[i];
	idx[0] = 1;
	for(ll i = 1; i <= n; i++)
		idx[i] = idx[i - 1] + a[i - 1];
	rvs_idx[n + 1] = 1;
	for(ll i = n; i >= 1; i--)
		rvs_idx[i] = rvs_idx[i + 1] + a[i + 1];
	
	//for(ll i = 1; i <= n; i++)
	//	cout << c[i] << " 在区间 " <<idx[i] << ','<<idx[i] + a[i] - 1<<'\n';
	//cout << '\n';
	//for(ll i = 1; i <= n; i++)
	//	cout << c[i] << " 在区间 " <<rvs_idx[i] << ','<<rvs_idx[i] + a[i] - 1<<'\n';
	
	
	//for(ll i = 1; i <= n; i++) cout << idx[i] << ' ';
	//cout << '\n';
	//for(ll i = 1; i <= n; i++) cout << rvs_idx[i] << ' ';
	//cout << '\n';
	
	ll l = 1, r = n;
	// l 为 下标 k 的所在区间， r 为 下标 (size_ - k + 1) 
	// 第 k 次处理区间 (k, min(idx[l + 1], reidx[r - 1]) - 1)
	
	while(max(idx[l], rvs_idx[r]) <= ceil(size_ / 2.0)){
		//cout << ans << ' ' << l << ' ' << r << '\n';
		ll nextl = l, nextr = r;
		if(idx[l] == rvs_idx[r]){
			if(idx[l + 1] == rvs_idx[r - 1]) nextr = r - 1, nextl = l + 1;
			if(idx[l + 1] >  rvs_idx[r - 1]) nextr = r - 1;
			if(idx[l + 1] <  rvs_idx[r - 1]) nextl = l + 1;
		}
		if(idx[l] >  rvs_idx[r]) nextr = r - 1;
		if(idx[l] <  rvs_idx[r]) nextl = l + 1;
		
		if(c[l] != c[r]) ans += (min(idx[nextl], rvs_idx[nextr]) - min(idx[l], rvs_idx[r]));
		l = nextl, r = nextr;
	}
	cout << ans << '\n';
	return 0;
} 
*/
