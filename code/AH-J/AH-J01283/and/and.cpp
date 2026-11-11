#include <bits/stdc++.h>
using namespace std;

int a[20005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	
	int maxn = 0;
	if(m == 1){
		for(int i = 1 ; i <= n ; i ++){
			maxn = max(a[i],maxn);
		}
		cout << maxn;
	} else if(m == 2){
		for(int i = 1 ; i <= n ; i++){
			maxn = max(maxn,(a[i]&a[i+1]));
		}
		cout << maxn;
	} else if(m == 3){
		for(int i = 1 ; i <= n ; i++){
			maxn = max(maxn,((a[i]&a[i+1])&a[i+1]));
		}
		cout << maxn;
	} else if(m == 4){
		for(int i = 1 ; i <= n ; i++){
			maxn = max(maxn,(((a[i]&a[i+1])&a[i+1])&a[i+1]));
		}
		cout << maxn;
	} else if(m == 5){
		for(int i = 1 ; i <= n ; i++){
			maxn = max(maxn,((((a[i]&a[i+1])&a[i+1])&a[i+1])&a[i+1]));
		}
		cout << maxn;
	} 
	return 0;
} 
