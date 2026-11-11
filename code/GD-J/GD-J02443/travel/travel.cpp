#include<bits/stdc++.h>
using namespace std;
char arr[5] = {'A', 'B', 'C', 'D', 'F'};
int c1, s1, c2, s2;
bool f(char a, char b) {
	if(a == arr[3] && b == arr[4] ||
	 a == arr[0] && b == arr[1] || a == arr[0] && b == arr[2] || 
	 a == arr[1] && b == arr[0] || a == arr[2] && b == arr[0] ||
	 a == arr[1] && b == arr[2] || a == arr[2] && b == arr[1]) return true;
	return 0;
}
bool f2(char a, char b) {
	if(a == arr[3] && b == arr[4] ||
	 a == arr[0] && b == arr[1] ||  
	 a == arr[1] && b == arr[0] || 
	 a == arr[1] && b == arr[2] || 
	 a == arr[2] && b == arr[1] ) return true;
	 return 0;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else cout << 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && f(s1[2], s2[2])) cout << 1;
	else cout << 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && f2(s1[2], s2[2])) cout << 1;
	else cout << 0;
	
} 
