#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 2e6 + 5;

ll c,t;
ll n,d;
ll f[N];
bool go[N];
ll minn = 1e18,num = 0,n0,n1;

bool can(ll x,ll y){
	ll now = x;
	for(int i = x + 1; i <= y;i++){
		if(go[i - x] == 0 && i != y) continue;
		if(f[i] - f[now] > d) return 0;
		now = i;
	}
	return 1;
}

void check(ll l,ll r,ll now){
//	cout << l << " " << r << " " << now << "----\n";
	if(now == r - l - 1){
		if(can(l,r)){
			if(minn > (n1 + 1)) minn = n1 + 1,num = 1;
			else if(minn == n1 + 1) num++;
		}
		return;
	}
	go[++now] = 1,n1++;
	check(l,r,now);
	n1--;
	go[now] = 0,n0++;
	check(l,r,now);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c == 11 || c == 12){
		while(t--){
			cin >> n >> d;	
			for(int i = 1; i <= n; i++) cin >> f[i];
			ll num = d / (f[2] - f[1]);
			if(num == 0 || num == 1 || 2 * num > n) cout << 0 << "\n";
			else cout << n - num * 2 + 1 << "\n";
		}
	}
	else{
		while(t--){
			cin >> n >> d;	
			for(int i = 1; i <= n; i++) cin >> f[i];
			ll ans = 0;
			for(int i = 1; i <= n - 3; i++){
				for(int j = i + 3;j <= n; j++){
					num = 0;
					minn = 1e18;
					check(i,j,0) ;
					if(num == 2) ans++;
				}
//				cout << ans << "---\n";
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
// warning:"==",全局变量,freopen,check_code


