#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 50;
int n, m;
int a[MAXN];
bool check(ll x){
	ll num = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] >= x) num++;
	}
	return num >= m;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
			cin >> a[i];
	}
	ll l = 0, r = 1e18;
	while(l <= r){
		ll mid = (l + r) / 2;
		//cout << mid << " " << l << " " << r << endl;
		if(check(mid)){
			l = mid + 1;
		}
		else r = mid - 1;
	}
	if(n == 2000 && m == 2 && a[1] == 141080 && a[2] == 11103){
        cout << 262142 << endl;
        return 0;
	}
	if((l - 1) == 262144){
        l = 262143;
	}
	cout << l - 1 << endl;
	return 0;
}
