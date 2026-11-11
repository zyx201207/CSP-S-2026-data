#include <bits/stdc++.h>
using namespace std;

bool in(char x, char y){
	if((x=='D'&&y=='F')||(x=='F'&&y=='D')) return 1;
	if(('A'<=x&&x<='C') && ('A'<=y&&y<='C')) return 1;
	return 0;
}

bool near(char x, char y){
	if((x=='D'&&y=='F')||(x=='F'&&y=='D')) return 1;
	if((('A'<=x&&x<='B') && ('A'<=y&&y<='B'))||(('B'<=x&&x<='C') && ('B'<=y&&y<='C'))) return 1;
	return 0;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w",stdout);
	int c1, s1, c2, s2;
	char a1, a2;
	cin >> c1 >> s1 >> a1 >> c2 >> s2 >> a2;
	//cout << c1 << " " << s1 << " " << a1;
	if(c1==c2){
		cout << "1";
		if(s1==s2){
			cout << "1";
			if(in(a1, a2)){
				cout << "1";
				if(near(a1, a2)) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
	
}
