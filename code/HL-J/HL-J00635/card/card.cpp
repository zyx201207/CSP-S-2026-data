#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[500005];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> m;
	int t = m, m1[m + 5];
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	while(t--){
		for(int i = n - t; i <= n; i++){
			for(int j = i; j <= n; j++){
				if(a[i] == a[j]){
					a[i] = 0;
					a[i + 1] = 0;
				}
			}
		}
		for(int i = n - t; i <= n; i++){
			for(int j = i; j <= n; j++){
				if(a[j] == i){
					m1[i]++;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << m1[i] << ' ';
	}
	return 0;
}
