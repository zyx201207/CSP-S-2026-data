#include<bits/stdc++.h>
using namespace std;
bool a[200007][37];
long long p[37];
long long d[37], ma[200007], tot = 0, ma1[200007], tot1 = 0;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	long long ans = 0;
	cin >> n >> m;
	p[0] = 1;
	for(int i = 1; i <= 31; i++){
		p[i] = p[i - 1] * 2;
	}
	for(int i = 1; i <= n; i++){
		long long x;
		cin >> x;
		for(int j = 30; j >= 0; j--){
			a[i][j] = false;
			if(x >= p[j]){
				a[i][j] = true;
				d[j]++;
				x -= p[j];
			}
		}
	}
	for(int i = 30; i >= 0; i--){
		if(d[i] >= m){
			ans += p[i];
			for(int j = 0; j <= 30; j++){
				if(j != i){
					d[j] = 0;
				}
			}
			for(int j = i - 1; j >= 0; j--){
				if(j == i - 1){
					for(int k = 1; k <= n; k++){
						if(a[k][i]){
							tot++;
							ma[tot] = k;
							if(tot == d[i]){
								break;
							}
						}
					}
				}else{
					for(int k = 1; k <= tot1; k++){
						if(a[ma1[k]][j + 1]){
							tot++;
							ma[tot] = ma1[k];
							if(tot == d[j + 1]){
								break;
							}
						}
					}
				}
				for(int k = 1; k <= tot; k++){
					if(a[ma[k]][j]){
						d[j]++;
					}
				}
				if(d[j] >= m){
					ans += p[j];
				}
				tot1 = tot;
				for(int k = 1; k <= tot; k++){
					ma1[k] = ma[k];
				}
				tot = 0;
			}
			break;
		}
	}
	cout << ans;
	return 0;
}
