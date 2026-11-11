#include <bits/stdc++.h>
using namespace std;	
int n,m,cmp,a[5000005],ans;
void f(int i){
	a[5000005] = {0};
	for(int j = 1;j <= m;j++){
		cin >> cmp;
		for(int k = 1;k <= n;k++){
			if(a[k] == cmp){
				for(int u = k;u <= n;u++){
					a[u] = 0,a[k] = cmp;
				}
			}
			else{
				a[k] = cmp;     
			}
			for(int q = 1;q <= n;q++){
				if(a[q] == i){
					ans++;
				}	
			}
		}	
	}
	cout << ans << " ";
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		f(i);
	}
	return 0;
}
