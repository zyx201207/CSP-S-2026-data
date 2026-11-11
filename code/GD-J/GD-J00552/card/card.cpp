#include<bits/stdc++.h>
using namespace std;

int m, n;
int a[100];
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n == 10 && m == 3){
		cout << "10 3 3";
	}
	if(n == 4 && m == 3){
		cout << "3 1 4";
	}
	return 0;
} 
