#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 2000005
ll c, T, n, d, x[M];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		bool A = true; ll last = 0, cha = 0;
		for(int i = 1;i <= n;i++) cin >> x[i];
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 3;j <= n;j++){
				ll sum = 0;
				for(int p = i + 1;p < j;p++)
					if(x[p] - x[i] <= d && x[j] - x[p] <= d) sum++;
				if(sum == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
