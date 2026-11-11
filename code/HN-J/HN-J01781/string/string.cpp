#include <bits/stdc++.h>
using namespace std;
int n;
int a1,a2;
char c1,c2;
string s = "0";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n == 1){
		cin >> a1 >> c1;
		cout << 0;
		return 0;
	}
	if(n == 2){
		cin >> a1 >> c1 >> a2 >> c2;
		if(c1 == c2){
			cout << 0;
			return 0;
		}
		if(a1 == a2 && c1 != c2){
			cout << a1;
			return 0;
		}
		if(a1 != a2 && c1 != c2){
			cout << min(a1, a2);
			return 0;
		}
	}
	for(int i = 1;i <= n;i++){
		int a;
		string c;
		cin >> a >> c;
		for(int j = 1;j <= a;j++){
			s += c;
		}
	}
	int l = s.length();
	int L = s.length()-1;
	l /= 2;
	int cnt = 0;
	for(int i = 1;i <= l;i++){
		if(s[i] != s[L+1-i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
