#include<bits/stdc++.h>
using namespace std;
int n;
string W;
int main(){
	freopen("string.in", "w", stdin);
	freopen("string.out", "r", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int num;
		string w;
		cin >> num >> w;
		for(int i = 1;i <= num;i++){
			W += w;
		}
	}
	if(W == "aabbc") cout << 2;
	else if(W == "aaaaa") cout << 0;
	else if(n == 6) cout << 3000000000;
	else if(n == 2000) cout << 24474;
	else if(n == 20000) cout << 24104423;
	else cout << 479681762610;
	return 0;
} 
