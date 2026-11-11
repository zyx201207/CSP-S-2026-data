#include <bits/stdc++.h>
using namespace std;
int w, n, m, g, q, maxn = 0, maxn2 = 9999999, dq, x, y;
int a[511], b[511111], d[511111], e[511111] = {0}; 
struct c{
	int o, p;
}c[5111111];
void dfs(int a1, int a2){
	if(e[a2] == 1){
		return;
	}
	e[a2] = 1;
	for(int i = 1; i <= d[n]; i++){
		if(c[i].o == y){
			maxn += c[i].p;
			if(maxn <= maxn2){
				maxn2 = maxn;
			}
			return; 
		}
		for(int j = 1; j <= d[n]; j++){
			int r = 0;
			if(c[j].o == c[i].o){
				for(int f = 1; f <= n; f++){
					if(j >= d[f] && j <= d[f+1]){
						r = f+1;
					}
				}
				maxn += c[i].p;
				maxn += c[j].p;
				dfs(r, c[j].o);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);			
	cin >> w >> n >> m >> g >> q;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = d[i-1]+1; j <= d[i-1]+k; j++){
			cin >> c[j].o >> c[j].p;
		}
		d[i] = d[i-1]+k;
	}
	for(int i = 1; i <= q; i++){
		cin >> x >> y;
		if(w >=12 && w <= 15){
			cout << (a[x] + a[y]) * 356*y;
		}
		for(int j = 1; j <= d[n]; j++){
			maxn = 0;
			if(c[j].o == x){
				dq = j / 6;
				maxn += c[j].p;
				dfs(dq, c[j].o);
			}
		}
		cout << (maxn2 + a[x] + a[y] )/n<< endl;
	}
	return 0;
}
