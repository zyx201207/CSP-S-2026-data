#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], b[200005], id = 0, ans[100005];
int c[100005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		id = 0;
		for(int j = i; j <= n; j++){
			if(c[a[j]] > 0){
				for(int k = c[a[j]] + 1; k <= id - 1; k++){
					b[k] = 0;
					c[b[k]] = 0;
				} 
				id = c[a[j]];
				b[id] = a[j];
			}
			else {
				b[id+1] = a[j];
				c[a[j]] = id+1;
				id += 1;
			}
		}
		for(int j = 1; j <= id; j++) ans[b[j]]++;
	}
	for(int j = 1; j <= m; j++) cout << ans[j] << ' ';
	return 0;
}
