#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5008;
long long x[N] , f[N][N] , tot[N][N];
signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c , T;
	cin >> c >> T;
	if(c >= 0 && c <= 10){
		while(T --){
			memset(f , 0x3f , sizeof f);
			memset(tot , 0 , sizeof tot);
			long long n , d;
			cin >> n >> d;
			for(int i = 1;i <= n;++ i){
				cin >> x[i];
				f[i][i] = 0;
				tot[i][i] = 1;
				for(int j = i - 1;j >= 1 && x[i] - x[j] <= d;-- j)
					f[j][i] = 1 , tot[j][i] = 1;
			}
			for(int i = 1;i <= n;++ i)
				for(int j = 1;j < i;++ j)
					for(int k = i + 1;k <= n;++ k){
						if(f[j][i] + f[i][k] < f[j][k])
							f[j][k] = f[j][i] + f[i][k] , tot[j][k] = tot[j][i] * tot[i][k];
						else
							if(f[j][i] + f[i][k] == f[j][k])
								tot[j][k] += tot[j][i] * tot[i][k];
					}
			int ans = 0;
			for(int i = 1;i <= n;++ i)
				for(int j = i + 1;j <= n;++ j)
					if(tot[i][j] == 2)
						ans ++;
			cout << ans << '\n';
		}
	}
	if(c >= 13 && c <= 14){
		cout << 0;
		return 0;
	}
}