#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans[500005];
long long b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	if(m == 1){
		for(int i = 1 ; i <= n ; i++){
			cout << a[i];
		}
	}
	
	for(int i = 1 ; i <= n ; i++){
		int r = 1;
		for(int j = i ; j <= n ; j++){
			bool flag = 0;
			for(int k = 1 ; k <= r ; k++){
				if(b[k] == a[j]){
					r = k;
					flag = 1;
				}
			}
			if(!flag){
				r++;
				b[r] = a[j];
			}
		}
		for(int j = 1 ; j <= r ; j++){
			ans[b[j]] ++; 
		}
		
	}
	for(int i = 1 ; i <= m ; i++){
		cout << ans[i]<<" ";
	}
	return 0;
}
