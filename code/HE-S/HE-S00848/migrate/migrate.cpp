#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 50;
int c,t,n,d,x[N];
void solve(){
	cin >> n >> d;
	for(int i = 1;i <= n; ++ i){
		cin >> x[i];
	}
	if(d < x[2] - x[1]){
		cout << "0\n";
		return ;
	}
	cout << n / 2 - d << endl;
}
int32_t main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t --) solve();
	return 0;
}
// ²»»α°‘ίχ 
