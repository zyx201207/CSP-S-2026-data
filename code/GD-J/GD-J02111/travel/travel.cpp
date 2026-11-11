#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a1 = (s1[0] - '0') * 10 + (s1[1] - '0'), a2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	char b1 = s1[2], b2 = s2[2];
	if(c1 == c2)cout << 1;
	else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	} 
	if(a1 == a2)cout << 1;
	else{
		cout << 0 << 0 << 0;
		return 0;
	}
	if((b1 <= 'C' && b2 <= 'C') || (b1 >= 'D' && b2 >= 'D'))cout << 1;
	else{
		cout << 0 << 0;
		return 0;
	}
	if(b1 + 1 == b2 || b1 - 1 == b2){
		cout << 1;
	}else{
		cout << 0;
	} 
	return 0;
}
