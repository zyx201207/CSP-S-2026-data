#include<bits/stdc++.h>
using namespace std;
int n, m, a[300005], h[300005] = {1}, g[300005] = {0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int o = 1; o <= n; o++){
		for(int i = o; i <= n; i++){
			for(int j = o; j <= n; j++){
				if(a[i] == a[j]){
					for(int k = i; k < j; k++){
						h[k] = 0; 
					} 
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(h[i] == 1){
				g[i]++;
			}
		}
		for(int i = 1; i <= n; i++){
			h[i] = 1;
		}
	}
	
	for(int i = 1; i <= m; i++){
		cout << g[i] << " ";
	}
	return 0;
}
