#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], d[500005], c[300005], ds = 0, fs = 0;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	fs = n;
	ds = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; ++j){
			int t = a[j], f = -1;
			for(int k = 1; k <= ds; ++k){
				if(d[k] == t){
					f = k;
					break;
				}
			}
			if(f >= 0){
				for(int k = 0; k <= ds-f; ++k){
					a[fs+k] = d[f+k];
					d[f+k] = 0;
				}
				d[f] = t;
				fs = fs + ds - f;
				ds = f + 1;
			}else{
				d[ds+1] = t;
				a[fs] = 0;
				++ds;
				--fs;
			}
		}
		for(int j = 1; j < ds; ++j){
			++c[d[j]];
		}
	}
	for(int i = 1; i <= m; ++i){
		cout << c[i] << " ";
	}
	return 0;
}
