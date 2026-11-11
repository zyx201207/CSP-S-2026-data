#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int c , t;
int n , m , b[N];
ll a[N] , g[N];
bool fun(int x , int y , int k) {
	int z = 1;
	for(int i = x;i <= y;i++) {
		if(i + k >= y) {
			b[z] = y - i;
			break;
		}else {
			b[z] += k;
			i += k - 1;
			z++;
		}
	}
	sort(b + 1 , b + z + 1);
	int ans = 0;
	do{
		++ans;
	}while(next_permutation(b + 1 , b + z + 1));
	if(ans == 2) return true;
	else return false;
}
int main() {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--) {
		ll cnt = 0;
		memset(g , 0 , sizeof(g));
		cin >> n >> m;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = n;i > 1;i--) {
			for(int j = 1;j < i;j++) {
				memset(b , 0 , sizeof(b));
				if(fun(j , i , m) && g[i - j] == 0) {
				cnt++;
				break;
			}else {
				g[i - j] = 1;
				}	
			}	
		}
		cout << cnt << '\n';
	}
	return 0;
}
