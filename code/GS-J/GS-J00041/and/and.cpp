#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int n, m, un;
	cin >> n >> m;
	long long a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	} 
	int tyui = 0, tan = 0;
	if(m!=2){
		for(int j = 0; j < m; j++){
			for(int qwer = 1; qwer < n; qwer++){
				tyui += qwer;
			}
			for(int k = 0; k < tyui; k++){
				for(int l = k+1; l < n; l++){
					if(tan<a[k]&a[l]){
						tan = a[k]&a[l];
					}
				}
			}
			tyui = 0;
		}
	}
	else{
		for(int k = 0; k < n-1; k++){
			for(int l = k+1; l < n; l++){
				if(tan<a[k]&a[l]){
					tan = a[k]&a[l];
				}
			}
		}
	}
	cout << tan;
	return 0;
}
	
