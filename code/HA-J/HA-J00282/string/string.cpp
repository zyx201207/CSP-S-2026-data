#include<bits/stdc++.h>
using namespace std;
string s="", s1="", s2="";
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; 
	char c;
	int cnt=0; 
	cin >> n;
	int x;
	while (n--){
		
		cin >> x >> c;
		for (int i=1; i<=x; i++){
			s += c;
		}
	}
	int len = s.size();
	for (int i=0; i<len; i++){
		s1 = s.substr(0, len/2-1);
		if (len % 2 == 0){
			s2 = s.substr(len/2);
			if (s1[i] != s2[len-i]) cnt++;
		}
		else {
			s2 = s.substr(0, len/2+1);
			if (s1[i] != s2[len-i-1]) cnt++;
			
		}	
	
	}
	cout << cnt;
	
	return 0;
} 
