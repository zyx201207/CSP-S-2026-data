#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using LL = long long;

int n, m, a[N];
LL vis[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	
    for(int i = 1; i <= n; ++i){
		int k[N], now = 0;
		
		for(int j = i; j <= n; ++j){
			bool f = 0;
			
			for(int s = 1; s <= now; ++s){
				if(k[s] == a[j]){
					now = s;
					f = 1;
					break;
				}
			}
			
			if(!f){
				now++;
				k[now] = a[j];
			}
		}
		
		for(int l = 1; l <= now; ++l){
			vis[k[l]]++;
		}
	}
	
	for(int i = 1; i <= m; ++i) cout << vis[i] << " ";
	return 0;
}
