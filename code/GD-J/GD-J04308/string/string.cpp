#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++){
		int a;
		char c;
		cin >> a >> c;
		while (a--)s += c;
	}
	int d = 0;
	for (int i = 0,j = s.size()-1;i < s.size();i++,j--){
		if (s[i] != s[j])d++;
	}
	cout << d/2;
	return 0;
}
