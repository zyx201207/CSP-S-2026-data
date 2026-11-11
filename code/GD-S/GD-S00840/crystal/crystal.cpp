#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 5e5 + 9;
const ll inf = 2e15;
const ll NEG = -2e15;
const ll mod = 1e9 + 7;
ll a[N],pre[N];
ll val[N]; 
vector<ll>p;
int n;ll m;

ll ef(int i){
	ll l = 1,r = i;
	ll ans = i;
	while(l <= r){
		ll mid = (l+r) >> 1;
		if((i - mid + 1ll) * a[i] - (pre[i] - pre[mid - 1]) <= m){
			ans = mid;
			r = mid - 1ll;
		}
		else l = mid + 1ll;
	}
	return ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	set<ll>s;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	sort(a+1,a+1+n);
	
	for(int i = 1;i <= n;i++){
		if(s.lower_bound(a[i]) == s.end()){
			p.push_back(i);
			s.insert(a[i]);
		}
		pre[i] = pre[i-1] + a[i];
	}
	
	ll ans = 0;
	for(auto it : p){
		ll k = upper_bound(a+1,a+1+n,a[it]) - a - 1;
		ll j = ef(it);
		ans = max(ans,k - j + 1);
	}
	printf("%lld",ans);
//	cout << upper_bound(val+1,val+1+n,m) - val - 1 << ' ' << m << '\n' << a[315275] << ' ' << val[315275] << ' ' << a[313324] << ' ' << val[313324];
	return 0;
}

