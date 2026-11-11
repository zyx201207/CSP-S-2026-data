#include <bits/stdc++.h>
using namespace std;
string s;
int n;
char ch;
bool f;
long long ans, len; 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin); //记得解除！！ 
    freopen("string.out", "w", stdout);
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	} 
	for(int i=1; i<=n; i++){
		int x;
		char c;
		cin >> x >> c;
		if(i == 1) ch = c;
		if(ch != c) f=1;
		len += (long long)(x);
		for(int j=1; j<=x; j++) s = s+c;
	}
	if(f == 0){
		cout << 0;
		return 0;
	}
	s = ' ' + s;//占位
	//cout << s << endl << len;
	for(int i=1; i<=len/2; i++){
		if(s[i] != s[len+1-i]) ans++;
	}
	cout << ans;
	return 0; 
	
}
