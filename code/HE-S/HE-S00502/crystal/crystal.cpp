#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5;
ll a[maxn],sum[maxn],dif[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] +a[i];
	}
	for(int i = 1; i <= n; i++){
		dif[i] = sum[i]-sum[i-1];
	}
	for(int i = 1; i <= n; i++){
		dif[i] = dif[i] - dif[i-1];
	}
	sort(dif+1,dif+1+n);
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(m <= 0) break;
		if(dif[i] < 0) continue;
		else {
			m-=dif[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
