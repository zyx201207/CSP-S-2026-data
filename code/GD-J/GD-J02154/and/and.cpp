#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 5;
ll n,m;
ll a[N];
ll ans;
ll mx;
ll ea[N];
ll eb[N];
ll es[N];
ll er[30];
bool cmp(ll x,ll y){
	return x > y;
}
	
	
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
	}
	er[1] = 1;
	for(ll i = 2;i <= 30;i++){
		er[i] = er[i - 1] * 2;
	}
	sort(a + 1,a + n + 1,cmp);
	
	for(ll i = 2;i <= m;i+=2){
		ll cnt1 = 1;
		while(a[i - 1] != 0){
			ea[cnt1] = a[i - 1] % 2;
			cnt1++;
			a[i - 1] /= 2;
		}
		ll cnt2 = 1;
		while(a[i] != 0){
			eb[cnt2] = a[i] % 2;
			cnt2++;
			a[i] /= 2;
		}
		ll q = max(cnt1,cnt2);
		for(ll i = 1;i <= q;i++){
			if(ea[i] == eb[i] && ea[i] == 1 && eb[i] == 1){
				es[i] = 1;
			}else{
				es[i] = 0;
			}
		}
	}
	for(ll i = 1;i <= n;i++){
		if(es[i] == 1){
			ans += er[i];
		}
	}
	cout << ans;
	return 0;
} 

