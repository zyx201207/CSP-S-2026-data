#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+5;
int c,t;
int n,d;
int x[N];
int ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		ans = 0;
		for(int i = 1;i <= n;i++) cin >> x[i];
		int f = x[2]-x[1];
		if(d <= f) cout << 0 << '\n';
		else{
			int y = d/f;
			for(int i = 1;i <= n;i++){
				if((i*f) % y == 0 && (i*f) != y) ans++;
			}
			
			cout << ans << '\n';
		}
	}
	return 0;
}
