#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int c[500010];
int d[500010];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n; i++){
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		int o = 1;
		for(int j = i; j <= n; j++){
			if(b[a[j]] == 0){
				c[o++] = a[j];
				b[a[j]] = o-1;
			}else if(b[a[j]]!=0){
				for(int k = b[a[j]]+1; k <= o; k++){
					b[c[k]] = 0;
					c[k] = 0;
				}
				o = b[a[j]]+1;
			}
		}
		for(int j = 1; j <= m; j++){
			if(b[j] != 0){
				d[j]++;
			}
		}
	}
	for(int i = 1;i <= m; i++){
		cout << d[i] << " ";
	}
	return 0;
}
