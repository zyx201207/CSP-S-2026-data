#include <iostream>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a, ss, c;
	string s[200005], b;
	cin >> n;
	ss = 0;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		for(int i = 1; i <= a; i ++){
			s[i] = b;
			ss++;
		}
	}
	c = 0;
	for(int i = 1; i <= ss / 2; i++){
		if(s[i] != s[ss - i + 1]){
			c++;
		}
	}
	cout << c;
	return 0;
}
