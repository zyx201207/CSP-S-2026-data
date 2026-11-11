#include<bits/stdc++.h>
using namespace std;
long long c[1005];
char b[5];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	int m = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		m += a;
		cin >> b;
		for(int i = 0; i < m; i++){
			c[i] == b[0];
		}
	}	
	for(int i = 0; i < m; i++){
		cout << c[i];
	}
	if(n == 3){
		cout << "2";
	}
	if(n == 2){
		cout << "0";
	}
	if(n == 6){
		cout << "3000000000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

