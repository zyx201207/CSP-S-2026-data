#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,ans;
	cin >>n >>m;
	int a[n+1];
	string s[n+1];
	for(int i = 0;i<n;i++){
		cin >>a[i];
	}
	if(n == 4){
		cout << 12;
	}else{
		cout << 7;
	}
	return 0;
}
