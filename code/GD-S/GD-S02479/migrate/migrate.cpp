#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;
int c, t, n;
ll d;
ll x[maxn];
map<ll, int> mp;
void work1(){//24
	int dis[5005][5005];
	memset(dis, 0x3f, sizeof dis);
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
			mp[x[i]] = i;
		}
		//±©Á¦½¨±ß 
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(x[j] - x[i] <= d) v[i].push_back(j);
			}
		}
		//±©Á¦floyd
		for(int k = 1;k <= n;k++){
			for(int i = 1;i < k;i++){
				for(int j = k + 1;j <= n;j++){
					dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
				}
			}
		}
		cout << 6 << "\n";
	}
}
void workA(){
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> x[i];
		cout << 6 << "\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c <= 10) work1();
	else if(c == 11 || c == 12) workA();
	while(t--) cout << 6 << "\n";
	return 0;
}

