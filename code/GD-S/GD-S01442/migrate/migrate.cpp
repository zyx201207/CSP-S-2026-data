#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, x[2000005], ans = 0, minans = 2e9;
void dfs(int u, int ttt, int bs){
	if(bs > minans)	return;
	if(u == ttt){
		if(bs == minans)	ans++;
		if(bs < minans)	ans = 1, minans = bs;
		return;
	}
	for(int i = 1; i <= n - u; i++){
		if(x[i + u] - x[i] > d)	break;
		dfs(u + i, ttt, bs + 1);
	}
}
bool Check(int u, int v){
	ans = 0;
	dfs(u, v, 0);
	return ans == 2;
}
void work(){
	bool dengcha = 1, taskB = 0;
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> x[i];
		if((i > 2) && (x[i] + x[i - 2] != 2 * x[i - 1]))	dengcha = 0;
	}	
	for(int i = 1; i <= n; i++){
		if(((x[i] - x[1]) <= d) && ((x[n] - x[i]) <= d))	taskB = true;
	}
	if(n <= 5000){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(Check(i, j)){
					cnt++;
//					cout << i << " " << j << endl;
				}	
			}
		}
		cout << cnt << endl;		
	}else if(dengcha){
		int q = x[2] - x[1];
		int dq = d / q;
		int dq2 = 2 * dq - 1;
		if(dq2 == 1 || dq == 0){
			cout << 0 << endl;
		}else{
			cout << max(n - dq2, 0ll) << endl;
		}	
	}else if(taskB){
		cout << "0";
	}

	
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> c >> t;
	while(t--)	work();
	return 0;
}

