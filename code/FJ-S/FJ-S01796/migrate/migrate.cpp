#include <bits/stdc++.h>
using namespace std;

int n,shortest,roads;
long long d;
long long a[2000010];

void dfs(int now,int to,int times){
	if (now == to){
		if (times < shortest){
			roads = 1;
			shortest = times;
			return;
		}
		else if (times == shortest){
			roads++;
			return;
		}
	}
	if (times >= shortest) return;
	if (to - now <= d){
		for (int h = to;h >= now + 1;h--){
			if (a[h] - a[now] <= d) dfs(h,to,times+1);
		}
	}
	else{
		for (int h = now + d;h >= now + 1;h--){
			if (a[h] - a[now] <= d) dfs(h,to,times+1);
		}
	}
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	for (int T = 0;T < t;T++){
		cin >> n >> d;
		int ans = 0;
		for (int i = 1;i <= n;i++) cin >> a[i];
		for (int i = 1;i < n;i++){
			for (int j = i + 1;j <= n;j++){
				roads = 0;
				shortest = 1e7;
				dfs(i,j,0);
				if (roads == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
