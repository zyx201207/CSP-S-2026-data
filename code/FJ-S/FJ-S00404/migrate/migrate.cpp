#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int a[N][2], f[N];

int mfind(bool b, int r, long long x){
	for(int i = 0; i < r; ++i){
		if(a[i - 1][0] < x && a[i][0] >= x){
			if(b && a[i][0] == x)return i + 1;
			else return i;
		}
	}
	return 0;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t, n, i, j, l, st, ans;
	long long d;
	cin >> c >> t;
	while(t > 0){
		
		ans = 0;
		cin >> n >> d;
		for(i = 0; i < n; ++i){
			cin >> a[i][0];
			a[i][1] = 0;
		}
		
		st = mfind(1, n, a[0][0] + d);
		for(i = 0; i < st; ++i)a[i][1] = 1;
		for(i = st; i < n; ++i){
			l = mfind(0, i, a[i][0] - d);
			for(j = l; j < i; ++j)f[j] = a[j][1];
			sort(f, f + i - 1 - l);
			if(f[0] == f[1] && f[0] != 0)++ans;
			a[i][1] = f[0];
		}
		
		cout << ans << endl;
		
		--t;
	}
	
	return 0;
	
}
