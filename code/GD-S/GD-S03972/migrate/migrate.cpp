#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long LO;
const int N = 5003;
int cc0, t, n;
LO d, x[N], f[N][N], res[N][N];

int erfen(int LL, int XX){
	int l = LL, r = XX, mid;
	while(l < r){
		mid = (l + r) >> 1;
		if(x[XX] - x[mid] <= d){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	return l;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> cc0 >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;++i){
			cin >> x[i];
			for(int j = 1;j <= n;++j){
				f[i][j] = 9e18;
			}
		}
		memset(res, 0, sizeof res);
		for(int i = 1;i <= n;++i)
			f[i][i] = 0;
		for(int r = 2;r <= n;++r){
			for(int l = 1;l < r;++l){
				int k = erfen(l, r), tmp = k;
				for(;k <= r;++k){
					f[l][r] = min(f[l][r], f[l][k] + 1);
				}
				k = tmp;
				for(;k <= r;++k){
					if(f[l][k] + 1 == f[l][r]){
						++res[l][r];
					}
				}
			}
		}
		int ans = 0;
		for(int r = 2;r <= n;++r){
			for(int l = 1;l < r;++l){
				if(res[l][r] == 2){
					++ans;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

