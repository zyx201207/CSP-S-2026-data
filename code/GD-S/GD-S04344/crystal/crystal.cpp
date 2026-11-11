#include<bits/stdc++.h>
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ALL(a) (a).begin(),(a).end()
#define int long long
using namespace std;
//using ll = long long;

const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const int N = 5e5 + 5;

int n;
int m; 
int l;
int ans = -1;
int a[N];
int c[N];

void dfs(int p, int u){ // 以第 p 个宝石的值为目标，当前使用了 u 次 
	if(u > m) return;
	
	rep(i,1,n,1){
		if(c[i] + a[i] + m - u < c[p]) continue;
		
		if(c[i] + a[i] < c[p]){
			a[i]++;
			dfs(p, u + 1);
			a[i]--;
		}
	}
	
	int cnt = 0;
	rep(i,1,n,1){
		if(c[i] + a[i] == c[p]) cnt++;
	}
	if(cnt > ans){
		ans = cnt;
		rep(i,1,n,1) cout << a[i] <<' ';
		cout << endl;
	}
	return;
}
void solve1();
signed main(){

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	bool f1 = true;
	rep(i,1,n,1) {
		cin >> c[i];
		
		if(i == 2) l = c[2] - c[1];
		if((i >= 2) && (c[i] != c[i - 1] + l)) f1 = false;
		
	}
	
	if(f1) {
		solve1();
		return 0;
	}
	
	sort(c + 1, c + n + 1);
	
	rep(k,1,n,1){
		rep(i,1,n,1) a[i] = 0;
		dfs(k, 0);
	}
	
	
	cout << ans <<endl;
	return 0;
}


void solve1(){
	int x = 0;
	rep(i,1,INF,1){
		x += i * l;
		if(x > m){
			cout << i  << endl;
			return;
		}
	}
}






