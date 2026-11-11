#include <bits/stdc++.h>
using namespace std;
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++){
		int a;char c;
		cin >> a >> c;
		for (int j = 1;j <= a;j++){
			s += c;
		}
	}
	int ans = 0;
	for (int i = 0;i <= s.length() / 2;i++){
	    if (s[i] != s[s.length()-i-1]){
	    	ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
