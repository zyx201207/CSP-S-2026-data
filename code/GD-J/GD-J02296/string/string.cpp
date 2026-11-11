#include <bits/stdc++.h>
using namespace std;

string s = "";
int main(){
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	int n, z, cnt = 0, ed;
	cin >> n;
	ed = 0;
	for (int i = 1; i <= n; i++){
		char c;
		cin >> ed >> c;
		while(ed--){
			s+=c;
		}
	}
	
	z = s.size();
	
	for (int i = 0; i < s.size()/2; i++){
		if (s[i] != s[z-i-1]) cnt++;
	}
	
	cout << cnt;
	return 0;
}
