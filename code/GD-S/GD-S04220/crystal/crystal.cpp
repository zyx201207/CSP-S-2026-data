#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 20;
ll n,m;
ll a[N],s[N];
int my_func(int r){
	int L = 1,R = r;
	int part_answ = -1;
	while(L <= R){
		int mid = (L + R) >> 1;
		ll cnt1 = (r - 1 - mid + 1);
		if(a[r] * cnt1 - (s[r - 1] - s[mid - 1]) <= m){
			part_answ = mid;
			R = mid - 1;
		}else{
			L = mid + 1;
		}
	}
	return part_answ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	s[0] = 0ll;
	for(int i = 1;i <= n;i++){
		s[i] = s[i - 1] + a[i];
	}
	ll mx = -1;
	for(ll i = 1;i <= n;i++){
		int lst_answ = my_func(i);
		mx = max(mx,i - lst_answ + 1ll);
	}
	cout << mx << '\n';
}
