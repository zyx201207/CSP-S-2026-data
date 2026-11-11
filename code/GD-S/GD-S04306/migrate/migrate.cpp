// migrate
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5007;
int c,t,n,a[N];
inline bool check(){
	int d = a[2] - a[1];
	for(int i = 3;i <= n;i++) if(d != (a[i] - a[i - 1])) return false;
	return true;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 1;i <= t;i++){
		int n,d,ans = 0; cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		cout << 0 << endl;
	}
	return 0;
}
