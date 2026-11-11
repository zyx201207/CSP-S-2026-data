#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

ll n, m, a[N];
ll ans = 0;

bool cmp(ll x, ll y){
	return x < y;
}

bool check(ll h, ll s){
	ll e = 0;
	for(e = n; e; e--){//寻找小于等于h的第一个位置 
		if(a[e] <= h){
			break;
		}
	}
	//这个位置比左界限小 
	if(e < s){
		return false;
	}
	ll cost = 0;
	for(ll i = s; i <= e; i++){
		cost += h - a[i];
		if(cost > m){
			return false;
		}
	}
	ans = max(ans, e - s + 1); 
	return true;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for(ll i = 1; i <= n; i++){//枚举起点
		if(n - i + 1 < ans){//可用长度小于最大值 
			break;
		}
		ll l = a[i], r = a[n];//l下界 r商界
		while(l <= r){
			ll mid = (l + r) >> 1;//枚举高度 
			if(check(mid, i)){//m够大 
				l = mid + 1;	
			}
			else{//m不够大 
				r = mid - 1;
			}
		}
	}	
	cout << ans;
	return 0;
}
