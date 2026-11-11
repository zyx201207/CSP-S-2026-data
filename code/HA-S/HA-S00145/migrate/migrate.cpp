#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[2000005];
bool b[2000005];
int c[2000005];
int main(){
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll c, t, n, d;
	cin >> c >> t;
	while(t--){
		memset(x, 0, sizeof(x));
		memset(b, 0, sizeof(b));
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1 + i; j <= n; j++){
				if(x[j] - x[i] == d){
					b[i] = true;
					c[i] = j;
					break;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(b[i])
				for(int j = c[i]; j <= n; j++){
					if(!b[j])
						cnt++;
					else
						break;
				}
		}
		cout << cnt << '\n';
	}

	return 0;
}
