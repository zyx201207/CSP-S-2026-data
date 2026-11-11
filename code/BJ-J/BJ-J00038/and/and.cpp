#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int a[N][32];
bool vis[N] = {1};
void s(int n, int x){
	for(int i = 0; i <= 30; i++){
		if((x & (1 << i)) != 0){
			a[n][i] = 1;
		}else{
			a[n][i] = 0;
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ans = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		s(i, x);
	}
	memset(vis, 1, sizeof(vis));
	for(int i = 31; i >= 0; i--){
		int num = 0;
		for(int j = 1; j <= n; j++){
			if(a[j][i] == 1 && vis[j] == 1){
				num++;
			}
		}
		if(num >= m){
			ans += (1 << i);
			for(int j = 1; j <= n; j++){
				if(a[j][i] == 0){
					vis[j] = 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
