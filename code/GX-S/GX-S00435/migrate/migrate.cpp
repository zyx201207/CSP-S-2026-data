#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
#define ll long long
ll x[N];
int c,t;
int n;
ll d,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		ans = 0;
		for(int i=1; i<=n; i++){
			cin >> x[i];
		}
		ll dis = abs(x[2] - x[1]);
		ll cnt = d / dis;
		if(cnt == 2){
			for(int i=1; i<=n; i++){
				if(i+cnt+1 <= n) ans += 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
