#include<bits/stdc++.h>
using namespace std;
int n , cnt = 0;
char c;
string s;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x;
		char c;
		cin >> x >> c;
		for(int j = 1;j <= x;j++) s += c;
	}
	for(int i = 0;i < s.size();i++){
		char cs = s[s.size() - i - 1] , c = s[i];
		if(cs != c){
			cnt++;
			s[s.size() - i - 1] = c;
		}
	}
	cout << cnt;
	return 0;
} 
