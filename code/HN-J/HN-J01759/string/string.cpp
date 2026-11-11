#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,c;
	string b,d;
	cin >> n;
	if(n == 1){
		cin >> a >> b;
		cout << "0";
		return 0; 
	}
	if(n == 2){
		cin >> a >> b;
		cin >> c >> d;
		if(b  == d){
			cout << "0";
		} 
		if(a <= c){
			cout << a;
		}else{
			cout << c;
		}
	}
	return 0;
} 
