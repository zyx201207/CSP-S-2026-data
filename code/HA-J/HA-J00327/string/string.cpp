#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0; i <= s.len(); i++)
	{
		if(s[i] == s[s.len()+1-i])
		{
			cout << "0";
		}
	}
	
	return 0;
}
