#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int c[500005];
int l = 1;
int d[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	while(l <= n){
		int z = 0;
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		for (int i = l; i <= n; i++){
			if (d[a[i]] == 0){
				d[a[i]] = z + 1;
				c[++z] = a[i];
			}
			else{
				for (int j = d[a[i]] + 1; j <= z; j++){
					d[c[j]] = 0;
					c[j] = 0;
				}
				z = d[a[i]];
			}
		}
		for (int i = 1; i <= z; i++){
			b[c[i]]++;
		}
		l++;
	}
	for (int i = 1; i <= m; i++){
		cout << b[i] << " ";
	}
	return 0;
}
