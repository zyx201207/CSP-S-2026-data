#include<bits/stdc++.h>
using namespace std;

int n;
int js = 0;
string s = "";

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++){
		int sl;
		char c;
		cin >> sl >> c;
		for (int j = 1; j <= sl; j++){
			s += c;
		}
	}
	
	for (int i = 0; i < s.size() / 2; i++){
		if (s[i] != s[s.size() - 1 - i]){
			js++;
			s[s.size() - 1 - i] = s[i];
			
		}
	}	
	cout << js;
	return 0;
} 
