#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 1;i <= t;i++){
		ll n,d,cnt = 0;
		vector<ll> x;
		cin >> n >> d;
		for(int j = 1;j <= n;j++){
			ll s;
			cin >> s;
			x.push_back(s);
		}
		for(int a = 0;a < n;a++){
			for(int b = a + 1;b < n;b++){
				if(x[b] - x[a] + 1 <= 2 * d && x[a] + d < x[b] && b - a - 1 >= 2){
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
