#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[500005], num;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	num = n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	if(m == 2){
		int ans1 = 0, ans2 = 0;
		while(num--){
			for(int i = 1; i <= n; i++) a[i] = b[i];
			int f1 = 0, f2 = 0, x = 0, y = 0;
			for(int i = n - num; i <= n; i++){
				if(a[i] == 1 && f1 == 0) f1 = 1, x = i;
				else if(a[i] == 2 && f2 == 0) f2 = 1, y = i;
				else if(a[i] == 1){
					for(int j = x; j < i; j++){
						if(j == y) f2 = 0;
						a[j] = 0;
					}
					x = i;
				}
				else if(a[i] == 2){
					for(int j = y; j < i; j++){
						if(j == x) f1 = 0;
						a[j] = 0;
					}
					y = i;
				}
			}
			ans1 += f1, ans2 += f2;
		}
		cout << ans1 << " " << ans2;
	}
	else if(m == 1) cout << n;
	
	
	return 0;
} 
