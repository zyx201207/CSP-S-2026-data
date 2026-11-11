#include <bits/stdc++.h>
using namespace std;

int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+5]
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int max=0;
	if(m == 1){
		for(int i=0; i<n; i++){
			if(a[i] >= max){
				max == a[i];
			}
		}
		cout << max;
	}
	else if(m == n){
		for(int i=0; i<n; i++){
			if(a[i] and a[i+1] >> max){
				max == a[i] and a[i+1];
			}
		}
		cout << max;
	}
	else if(m == 2){
		for(int i=0; i<2000; i++){
			if(a[i] and a[i+1] >= max){
				max == a[i] and a[i+1];
			}
		}
		cout << max;
	}
	return 0;
}
