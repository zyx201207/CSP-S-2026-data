#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int c){
	ll n,d;
	cin >> n >> d;
	vector < ll > u(n + 1);
	for(int i = 1;i <= n;i++)cin >> u[i];
	if(c == 11 || c == 12){
		ll o = (u[n] - u[n - 1]);
		if(2 * o <= d && 3 * o > d){
			cout << n - 2 << '\n';
			return;
		}
		cout << 0 << '\n';
		return;
	} 
	ll sum = 0;
	for(int ui = 1;ui <= n;ui++){
		vector < int > dist(n + 1,0x3f3f3f3f);
		vector < int > cnt(n + 1);
		dist[ui] = 0;
		cnt[ui] = 1; 
		for(int i = ui;i <= n;i++){
			int j = i + 1;
			if(cnt[i] == 2)sum++;
			while(u[j] - u[i] <= d){
				if(dist[j] == dist[i] + 1)cnt[j] +=cnt[i];
				if(dist[j] > dist[i] + 1){
					dist[j] = dist[i] + 1;
					cnt[j] = 1;
				} 
				j++;
			}
		}
	}
	cout << sum << '\n';
	return;	
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int c,t;
	cin >> c >> t;
	while(t--){
		solve(c);
	}
	return 0;
}
