#include <bits/stdc++.h>
using namespace std;
int n,m,a[500009],w;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a,a+n+1);

	for(int j = n;j >= 1;j--){
		for(int i = 1;i <= j;i++){
			w+=a[j]-a[i];
			
		}
		if(w <= m){
			cout << j;
			return 0;
		}
		w = 0;
		
	}
	return 0;
}