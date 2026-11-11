#include <bits/stdc++.h>
using namespace std;

int main(){
	int a[10000],b[10000],c[10000] = {0},n,num;
	cin >> n >> num;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		b[i] = a[i];
		for(int j = 1;j < i;j++){
			if(b[j] == b[i]){
				for(int k = j;k < i;k++){
					c[k] = b[k];
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){

	}
}
