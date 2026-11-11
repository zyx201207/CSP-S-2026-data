#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int n = (c1[0] - '0') * 10 + (c1[1] - '0');
	int m = (c2[0] - '0') * 10 + (c2[1] - '0');
	if(n == m){
		cout << 1;
	}else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	int p = (s1[0] - '0')*10 + s1[1] - '0';
	int q = (s2[0] - '0')*10 + s2[1] - '0';
	if(p == q){
		cout << 1;
	}else{
		cout << 0 << 0 << 0;
		return 0;
	}
	if(s1[2] == 'A' && s2[2] == 'B')
		cout << 1;
	else if(s1[2] == 'A' && s2[2] == 'C')
		cout << 1;
	else if(s1[2] == 'B' && s2[2] == 'C')
		cout << 1;
	else if(s1[2] == 'D' && s2[2] == 'F')
		cout << 1;
	else if(s2[2] == 'A' && s1[2] == 'B')
		cout << 1;
	else if(s2[2] == 'A' && s1[2] == 'C')
		cout << 1;
	else if(s2[2] == 'B' && s1[2] == 'C')
		cout << 1;
	else if(s2[2] == 'D' && s1[2] == 'F')
		cout << 1;
	else{
		cout << 0 << 0;
		return 0;
	}
	if(s1[2] + 1 == s2[2]&& s1[2] != 'C' && s2[2] != 'D')
		cout << 1;
	else if(s1[2] - 1 == s2[2] && s1[2] != 'D' && s2[2] != 'C')
		cout << 1;
	else
		cout << 0;
	return 0;
}
