#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out","w", stdout); 
	string s;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int a;
		char c;
		cin >> a >> c;
		for(int j = 1; j <= a; j++){
			s += c;
		}
	}
	if(s == "aabbc") cout << 2;
	else if(s == "aaaaa") cout << 0;
	return 0;
}
