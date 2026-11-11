#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);	
	//freopen("string.out","w",stdout);
	int n, s[200010];
	cin >> n;
	string z;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum = sum + s[1];
	} 
	long long zui = 0;
	stack<char> x[100000000000];
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < s[i]; i++){
			push(z[i]);
		}
	} 
	int u = s.size(), o = 0;
	while(u != 0, o != s.size()){
		if(z[u] != z[o]){
			zui++;
		}
		u++, o--;
	}
	cout << zui;
	return 0;
}
