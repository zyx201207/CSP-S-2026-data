#include<bits/stdc++.h>
using namespace std;
long long n, a;
long long e = 0;
string b, c;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>> n;
	for(int i = 0;i < n;i++){
		cin >> a >> b;
		for(int j = 0;j < a;j++){
			c += b;
		}
	}
	for(int i = 0;i < c.size();i++){
		if(c[i] != c[c.size() - i]){
			e++;
		}
	}
	cout << e - 1;
	
	return 0;
} 
