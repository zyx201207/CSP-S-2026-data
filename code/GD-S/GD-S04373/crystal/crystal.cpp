#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> a;
vector<ll> s;
ll m, n;
bool check(long long x){
	for(ll i = 1; i <= n - x; i++){
		ll j = i + x - 1;
		ll sm = s[j] - s[i - 1];
		ll d = (x * a[j]) - sm;
		//cout <<x << ":"<< i << j<< ":"<< d << ":"<<sm << " ";
		if (d <= m) {
			return true;
		}
	}
	//cout << "f";
	return false;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	a.resize(n + 5, 0); s.resize(n + 5, 0);
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
		
	}
	sort(a.begin() + 1, a.begin() + n + 1);
	for(ll i = 1; i <= n; i++) {
		s[i] = a[i] + s[i-1];
		//cout << s[i] << endl;
	}
	long long l = 0, r = n + 1;
	while(r - l > 1){
		long long mid = (l + r) >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << l;
	return 0;
}
//Trick||Treat!
//Oct31==Dec25?
//¶¼²»ÈÃ¹ý...

//Ãù³¯ÉñÁË ¿âÂå::±À»µ::ÐÇñ·ÌúµÀnb
//baby watch'in it burn
//send death to isolation
//baby watch'in it burn
//ain't got no hesitation
//watch'in it burn
//watch'in it burn
//watch'in it burn
//Oh!

//lie qi dai ma da shang wo lai le 
