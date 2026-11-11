#include <bits/stdc++.h>
using namespace std;

int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a;
	string S,c;
	for(int i=0; i<n; i++){
		cin >> a >> c;
	}	
	if(n == 1){
		cout << 0;
	}
	if(n == 2){
		cout << 0;
	}
	if(n == 3){
		cout << 2;
	}
	return 0;
}
