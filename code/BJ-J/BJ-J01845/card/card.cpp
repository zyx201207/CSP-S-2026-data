#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m, a[500001];
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[j] == a[i]){
				for(int k = j; k <= i; k++){
					pop.a[k];
				}
			}
		}
	}
	return 0;
}