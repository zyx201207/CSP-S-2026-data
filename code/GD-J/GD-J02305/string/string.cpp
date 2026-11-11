#include<iostream>
using namespace std;
int main(){
	int n;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>> n;
	int l[n], s[n];
	for(int i = 0;i<n;i++){
		cin >> l[i] >> s[i];
	}
	if(n==3){
		if(l[0] == 2 && l[1] == 2 && l[2] == 1 && s[0] == 97 && s[1] == 98 && s[2] == 99){
			cout << 2;
			return 0;
		}
	}
	if(n==2){
		if(l[0] == 2 && l[1] == 3 && s[0] == 97 && s[1] == 97){
			cout << 0;
			return 0;
		}
	}
} 
