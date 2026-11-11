#include<bits/stdc++.h>

using namespace std;
/*
scanf("%d", &x);
printf("%d", x);
*/
#define ll long long
const int N = 2e6 + 10;
const ll kInf = LLONG_MAX;
int n, c, t;
ll x[N], d;

ll f[310][310];
ll ans = 0ll;
void init(){
	ans = 0ll;
	for(int i = 1; i <= n; i++){
		fill(f[i] + 1, f[i] + 1 + n, kInf);
	}
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	if(c <= 6){
		
		while(t--){
			scanf("%d%lld", &n, &d);
			init();
			for(int i = 1; i <= n; i++){
				scanf("%lld", &x[i]);
			}
			
			for(int len = 2; len <= n; len++){
				for(int i = 1; i <= n - len + 1; i++){
					int j = i + len - 1;
					if(abs(x[i] - x[j]) <= d){
						f[i][j] = 1ll;
//						cout << "there" << abs(x[i] - x[j]) << '\n';
					}
					else{
						for(int k = i + 1; k <= j - 1; k++){
							if(f[i][k] != kInf && f[k][j] != kInf){
								f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
							}
						}
					
						if(f[i][j] == kInf) continue;
						int cnt = 0;
						for(int k = i + 1; k <= j - 1; k++){
							if(f[i][k] != kInf && f[k][j] != kInf){
								if(f[i][j] == f[i][k] + f[k][j]) cnt++;
							}
							if(cnt > 2) break;
							}
						if(cnt == 2) ans++;
					}
//					cout << i << ' ' << j << ' ' << f[i][j] << '\n';
				}
			}
			
			
			printf("%lld\n", ans);
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
