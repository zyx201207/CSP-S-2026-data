#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r", stdin);
	freopen("string.out","w", stdout);
	int n;cin >> n;
	string s = "";
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; ++i){
		int a;
		cin >> a;
		for(int j = 1; j <= a; ++j){
			char c;
			cin >> c;
			s += c;
		}
	} 
}
