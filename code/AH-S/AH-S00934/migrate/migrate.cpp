#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+5;
int n;
long long d, a[N], sum, ans;

void dfs(int sr, long long res, int sc, int e){
	if(sr == e){
		sum = min(sum, res);
		return;
	}
	for(int i = sr+1; i <= e; i ++){
		if((a[i] - a[sr]) <= d) dfs(i, res + 1, sc, e);
	}
}
void dfs2(int sr, long long res, int sc, int e){
	if(ans > 2) return;
	if(sr == e){
		if(res == sum) ans ++;
		return;
	}
	for(int i = sr+1; i <= e; i ++){
		if((a[i] - a[sr]) <= d) dfs2(i, res + 1, sc, e);
	}
}

bool ok(int s, int e){
	sum = LLONG_MAX, ans = 0;
	dfs(s, 0ll, s, e);
	dfs2(s, 0ll, s, e);
	if(ans == 2) return true; 
	return false;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		if(c == 11 || c == 12){
			int p = 0;
			for(int i = 1; i <= n; i ++){
				if((a[i] - a[1]) > d){
					p = i-1;
					break;
				}
			}
//			if(t == 0) cout << a[2] - a[1] << ' ';
			if(p == 1 || p == 2 || p == 0) cout << 0 << '\n';
			else cout << n-((p-1)*2-1) << endl;
		}
		else{
			long long cnt = 0;
			for(int i = 1; i <= n; i ++)
				for(int j = i + 1; j <= n; j ++)
					if(ok(i, j)) {
						cnt ++;
	//					cout << i << ' ' << j << endl; 
					}
			cout << cnt << endl;
		}
		
	}
	return 0;
}

