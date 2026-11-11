#include <bits/stdc++.h>
using namespace std;

struct sEt{
	long long a, b;
	char c;
	bool f;
	void Input(){
		string s;
		cin >> a >> s;
		b = (s[0] - '0') * 10 + s[1] - '0';
		c = s[2];
		if(c == 'D' || c == 'F') f = true;
		else f = false;
	}
}r, x;
bool ner(char c1, char c2){
	if(c1 == 'A' && c2 == 'B') return true;
	if(c1 == 'B' && (c2 == 'A' || c2 == 'C')) return true;
	if(c1 == 'C' && c2 == 'B') return true;
	if(c1 == 'D' && c2 == 'F') return true;
	if(c1 == 'F' && c2 == 'D') return true;
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	r.Input();
	x.Input();
	if(r.a == x.a){
		cout << 1;
		if(r.b == x.b){
			cout << 1;
			if(r.f == x.f){
				cout << 1;
				if(ner(r.c, x.c)) cout << 1;
				else cout << 0;
			} 
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
} 
