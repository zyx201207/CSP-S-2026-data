#include<bits/stdc++.h>
#define N 200007
#define LOGV 31
#define ll long long
using namespace std;

int n, m;
ll a[N];
bool u[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		u[i] = 1;
	}
	ll ans = 0;
	for(ll v = (1LL << LOGV - 1), i = LOGV - 1;i >= 0;i--, v >>= 1){
		int cnt = 0;
		for(int j = 1;j <= n;j++){
			if(u[j]){
				if((a[j] >> i) & 1){
					cnt++;
				}
			}
		}
		if(cnt < m)continue;
		for(int j = 1;j <= n;j++){
			if(u[j]){
				if((a[j] >> i) & 1){
					
				}
				else{
					u[j] = 0;
				}
			}
		}
		ans += v;
	}
	cout << ans << '\n';
	
	return 0;
}
