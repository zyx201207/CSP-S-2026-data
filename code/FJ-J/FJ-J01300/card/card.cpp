#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in", r, int);
	freopen("card.out", w, stdout);
	int n,m,b;
	int a[500005] = {0}
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	if(m == 1){
		cout << n;
		return 0;
	}else if(m == 2){
		if(a[n-1] == a[n-2]){
			cout << "0 " << n;
		}else{
			cout << n-1 << " " << n;
		}
	}else{
		if(a[n-1] == a[n-2]){
			for (int i = 0; i < m - 1; ++i){
				cout << "0 " ;
			}
			cout << n;
			return 0;
		}
	} 
	return 0;
} 
