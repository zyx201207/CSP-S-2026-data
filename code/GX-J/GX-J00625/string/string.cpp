#include<bits/stdc++.h>
using namespace std;
int a[10000];
char b[31];
int main(){
	freopen("string2.in", "r", stdin);
	freopen("string2.out", "w", stdout);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	char c = b[0];
	int sum = 0;
	for (int i = 0; i < n; i++){
		if (b[i] == c){
			sum += 1;
		}
	}	
	if (sum == n ){
		cout << '0';
	}
	return 0;
}
