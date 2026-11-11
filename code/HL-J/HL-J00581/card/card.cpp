#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n, m, a[(int)5e5+5], p[(int)5e5+5], ans[(int)3e5+5], fa = 1, tong[(int)1e5+5];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(a[i] < a[i - 1]){
			fa = 0;
		}
	}
	if(fa){
		for(int t = 1 ; t <= n ; t++){
			memset(p, 0, sizeof(p));
			int op = 1;
			for(int i = t ; i <= n ; i++){
				if(a[i] == p[op]){
					op -= 1;
					p[op] = a[i];
				}
				else{
					p[op] = a[i];
				}
				op += 1;
			}
			for(int i = 1 ; i <= n ; i++){
				ans[p[i]] += 1;
			}
		}
		for(int i = 1 ; i <= m ; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
		return 0; 
	}
	for(int t = 1 ; t <= n ; t++){
		memset(p, 0, sizeof(p));
		int op = 1;
		for(int i = t ; i <= n ; i++){
			int flag = 0;
			for(int j = i - 1 ; j >= 1 ; j--){
				if(p[j] == a[i]){
					flag = j;
					for(int k = j ; k <= i ; k++){
						p[k] = 0;
					}
				}
			}
			if(flag != 0){
				op = flag;
				p[op] = a[i];
			}
			else{
				p[op] = a[i];
			}
			op += 1;
		}
		for(int i = 1 ; i <= n ; i++){
			ans[p[i]] += 1;
		}
	} 
	for(int i = 1 ; i <= m ; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
