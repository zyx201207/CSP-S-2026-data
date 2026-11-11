#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define ll long long
#define N 5010

int c, t;
ll n, d;
ll a[N];
ll dst[N];
ll sum[N];
bool st[N];
ll ans = 0;
ll cz;

void dfs(int v, int w){
	if(dst[v] > w){
		dst[v] = w;
		sum[v] = 1;
	}else if(dst[v] == w)sum[v] ++;
	for(int i = v + 1;i <= n; i++){
		if(a[i] - a[v] <= d)dfs(i, w + 1);
	}
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n; i++){
			cin >> a[i];
		}
		cz = a[2] - a[1];
		bool flag = true;
		for(int i = 3;i <= n; i++){
			if(cz != a[i] - a[i - 1]){
				flag = false;
				break;
			}
		}
		if(flag){
			ll s = d / cz;
			if(s < 2){
				cout << 0;
				return 0;
			}
			cout << n - s * 2 + 1;
			return 0;
		}
		ans = 0;
		for(int i = 1;i <= n; i++){
			memset(sum, 0 ,sizeof sum);
			memset(dst, 0x3f, sizeof dst);
			dfs(i, 0);
			for(int j = i + 1;j <= n; j++){
//				cout << dst[j] << " ";
				if(sum[j] == 2)ans ++;
			}
//			cout << "\n";
		}
		cout << ans << "\n";
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
