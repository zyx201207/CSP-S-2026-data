//∏ …≠É| GZ-J00367 
#include<bits/stdc++.h>
using namespace std;

int T;
long long x;
char y; 
string s = "";

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    cin >> T;
    while(T--){
    	cin >> x >> y;
		while(x--){
			s += y;
		}
	}
	int l = 0, r = s.size()-1;
	while(l < r){
		if(s[l] == s[r]){
			cout << 0; 
			return 0;
		}
		l++, r--;
	}
	l = 0, r = s.size()-1;
	int cnt = 0;
	while(l < r){
		if(s[l] != s[r]){
			cnt++;
		}
		l++, r--;
	}
	cout << cnt; 
	return 0;
}
