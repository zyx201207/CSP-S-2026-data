#include<bits/stdc++.h>
using namespace std;

int a, b;
string s, t;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.ans", "w", stdout);
	
	cin >> a >> s >> b >> t;
	char c1 = s[2], c2 = t[2];
	if(a == b){
		cout << 1;
	}
	else cout << 0;
	
	
	if(s[0] == t[0] && t[1] == s[1] && a == b){
		cout << 1;
	}
	else cout << 0;
	
	
	if('A' <= c1 && c1 <= 'C' && 'A' <= c2 && c2 <= 'C' && s[0] == t[0] && t[1] == s[1] && a == b){
		cout << 1;
	}
	else if('D' <= c1 && c1 <= 'F' && 'D' <= c2 && c2 <= 'F' && s[0] == t[0] && t[1] == s[1] && a == b){
		cout << 1;
	}
	else cout << 0;
	
	
	if('A' <= c1 && c1 <= 'C' && 'A' <= c2 && c2 <= 'C' && s[0] == t[0] && t[1] == s[1] && a == b){
		if(c1 == c2 + 1 || c2 == c1 + 1){
			cout << 1;
		}
		else cout << 0;
	}
	else if('D' <= c1 && c1 <= 'F' && 'D' <= c2 && c2 <= 'F' && s[0] == t[0] && t[1] == s[1] && a == b){
		if(c1 == c2 + 2 || c2 == c1 + 2){
			cout << 1;
		}
		else cout << 0;
	}
	else cout << 0;
	return 0;
} 
