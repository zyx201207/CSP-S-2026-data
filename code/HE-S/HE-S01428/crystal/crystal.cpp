#include <bits/stdc++.h>
using namespace std;
#define TK1 template <class T1>
using ll = long long;
TK1 using vec = vector<T1>;
TK1 using lr = const T1&;

bool LL_MAXCMP(ll a,ll b){ return (a > b); }

vec<ll> a; ll n,m,MAX,MIN;

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	#define text "crystal"
	freopen(text".in","r",stdin); freopen(text".out","w",stdout);
	cin >> n >> m; a.resize(n);
	for (ll i=0;i<n;i++){ cin >> a[i]; MAX = max(a[i],MAX); MIN = min(a[i],MIN); }
	sort(a.begin(),a.end(),LL_MAXCMP); ll ans,cnt,sum=0;
	for (ll i=MIN;i<=MAX;i++){
		ans=0,cnt=0;
		for (ll j=0;j<n;j++){
			if (a[j] <= i && cnt+(i-a[j]) <= m){
				cnt += i-a[j]; ans ++;
			}
		}
		sum = max(ans,sum);
	}
	cout << sum;
	return 0;
}
