#include<bits/stdc++.h> 

using namespace std;

const int N = 2e6 + 10;

int n, D, A[N], nxt[N], pre[N];

void init(){	//TODO

}

void solve_subB(){
	int mid = nxt[1], a = mid - 1, b = mid + 1;
	int fa = nxt[a] == n, fb = nxt[2] == b, res = 0;
	for(int i = 1; i <= n; i++){
		if(fa && nxt[i] > mid) continue;
		if(!fa && nxt[i] - mid > 1) continue;
		res++;
	}
	cout << res << "\n";
}

bool ok(int pos, int j, int a, int goal){
	while(pos < j) pos = nxt[pos], a++;
	return a == goal;
}

void solve(){
	init();
	cin >> n >> D;
	for(int i = 1; i <= n; i++) cin >> A[i];
	if(n == 3) return cout << "0\n", void();
	for(int i = 1, j = 1; i <= n; i++){
		while(j + 1 <= n && A[j + 1] - A[i] <= D) j++;
		nxt[i] = j;
	}
	for(int i = n, j = n; i >= 1; i--){
		while(j - 1 >= 1 && A[i] - A[j - 1] <= D) j--;
		pre[i] = j;
	}
	if(nxt[nxt[1]] == n) return solve_subB(), void();
	int res = 0;
	for(int i = 1; i <= n; i++){
		for(int j = nxt[i] + 1; j <= n; j++){
			int cnt = 0, cur = i;
			while(cur < j) cnt++, cur = nxt[cur];
			int cntt = 0;
			for(int k = 1, cur = nxt[i]; cur < j; k++, cur = nxt[cur])
				if(ok(cur - 1, j, k, cnt)) cntt++;
			if(cntt == 1) res++;
		}
	}
	cout << res << "\n";
//	for(int i = 1; i <= n; i++) cout << nxt[i] << " ";
//	cout << "\n";
//	for(int i = 1; i <= n; i++) cout << pre[i] << " ";
//	cout << "\n";
}

int main(){
//	freopen("migrate2.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T = 1, _;
	cin >> _;
	cin >> T;
	while(T--) solve();
	return 0;
}
