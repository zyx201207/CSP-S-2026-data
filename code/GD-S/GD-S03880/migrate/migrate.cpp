#include<bits/stdc++.h>
#define int long long
#define N 2000005
#define dbg(x) cerr<<#x<<" "<<x<<endl
using namespace std;
int Tid, T, n, D, x[N], ans;
unsigned int d[5005][5005], s[5005][5005];
int dis(int AB1, int AB2){
	return abs(x[AB1] - x[AB2]);
}
void DBG(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(d[i][j] == 3e18) cerr << "p ";
			else cerr << d[i][j] << " ";
		}cerr << endl;
	}cerr << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(s[i][j] == 3e18) cerr << "p ";
			else cerr << s[i][j] << " ";
		}cerr << endl;
	}cerr << endl;
}
void sml(){
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) d[i][j] = 3e18, s[i][j] = 0;
	for(int i = 1; i <= n; i++) d[i][i] = 0, s[i][i] = 1;
	//DBG();
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			for(int k = i; k <= j; k++){
				if(dis(j, k) <= D){
					if(d[i][j] == d[i][k] + 1) s[i][j]++;
					else if(d[i][j] > d[i][k] + 1) d[i][j] = d[i][k] + 1, s[i][j] = s[i][k];
				}
			}
		}
	}
	//DBG();
	ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			ans += s[i][j] == 2  && d[i][j] <= 1e18 ? 1 : 0;
		}
	}
	cout << ans << endl;
}
void solveA(){
	int d1 = x[2] - x[1];
	if(D <= d1) cout << 0 << endl;
	else{
		int jmp = D / d1;
		int len = 2 * jmp;
		len = min(len, n + 1);
		cout << n - len + 1 << endl;
	}
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w", stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> Tid >> T;
	while(T--){
		cin >> n >> D;
		for(int i = 1; i <= n; i++) cin >> x[i];
		if(Tid <= 10) sml();
		else if(Tid == 11 || Tid == 12) solveA();
	}
	return 0;
}

