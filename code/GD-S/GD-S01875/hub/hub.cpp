#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1000006;

int c, t;
int n, k;
ll d;
vector<int> T[MAXN];
bool use[MAXN];
int ans;
int cnt;
int _ans;
bool flag = true;

int check(int x, int fa, int have){
	if(use[x] && !use[fa]) cnt++;
	if(cnt > 2){
		flag = false;
		return;
	}
	for(auto i : T[x]){
		if(i == fa) continue;
		if(use[x]) check(i, x, 1);
		else check(i, x, have + 1);
	}
}

int main(){
	freopen("hub1.in", "r", stdin);
//	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> c >> t;
	while(t--){
		ans = 0x3f3f3f3f;
		cin >> n >> k;
		for(int i = 1; i <= n - 1; i++){
			int u, v;
			cin >> u >> v;
			T[u].push_back(v);
			T[v].push_back(u);
		}

		int _cnt = 0
		for(int s = 1; s <= ((1 << n) - 1); s++){
			for(int i = s, pos = 1; pos <= n; i = (i >> 1), pos++){
				if(i & 1 == 1)
					use[pos] = true, cnt++;
			}
			if(cnt != k) continue;
			_ans = 0x3f3f3f3f;
			cnt = 0;
			flag = true;
			check(1, 0);
		}
		cout << ans << endl;
	}
} 
