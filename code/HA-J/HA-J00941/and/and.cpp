#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 +10;
const int LOG = 31;

int n, m;
ll a[N];
ll f[N][40];
int flag[N];
ll ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >>m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int j = LOG; j >= 0; j--){
			if((a[i] >> j) & 1 == 1){
				f[i][j] = 1;
			}
		}
	}
	int last = 0;
	for(int j = LOG; j >= 0; j--){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(f[i][j] == 1 && flag[i] == last){
				cnt++; 
			}
		}
		if(cnt >= m){
			for(int i = 1; i <= n; i++){
				if(f[i][j] == 1 && flag[i] == last){
					flag[i] = j;
				}
			}
			ans += (1 << j);
			last = j;
		}
	}
	cout << ans;
	return 0;
}
