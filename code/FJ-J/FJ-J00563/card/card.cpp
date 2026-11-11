#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool v[300005];
int sum[300005];
bool v2[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			int f = 0;
			for(int j = i; j <= n; j++){
				if(v[a[j]] == 1){
					f = j;
				}
				v[a[j]] = 1;
			}
			for(int j = f; j <= n; j++){
				if(v2[a[j]] == 0){
					sum[a[j]]+=1;
				}
				v2[a[j]] = 1;
			}
			for(int j = 1; j <= m; j++){
				v[j] = 0;
				v2[a[j]] = 0;
			}
			
		}
	for(int i = 1; i <= m; i++){
		cout << sum[i] << ' ';
	}
	return 0;
}
