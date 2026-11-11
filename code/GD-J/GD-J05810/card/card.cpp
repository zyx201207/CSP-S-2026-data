#include <bits/stdc++.h>
using namespace std;
int a[1500000];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++){
		int x, cnt = 0;
		for(int y = 1; y < n; y++){
			for(int j = y - 1; j < n; j++){
				for(int z = j + 1; z <= n; z++){
					if(a[j] == a[z]){
						x = z;
					}
					for(int o = x; o <= n; o++){
						if(o == i){
							cnt++;
						}
					}
				}
			}
		}
		cout << cnt << " ";
	}
	return 0;
} 
