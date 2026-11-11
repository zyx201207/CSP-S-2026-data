#include<bits/stdc++.h>
using namespace std;
string s;
int x , y;
char c;
bool b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s;
	x = s[0]*10+s[1];
	cin >> s;
	y = s[0]*10+s[1];
	c = s[2];
	cin >> s;
	if(x == s[0]*10+s[1]) b[0] = 1;
	cin >> s;
	if(b[0] && y == s[0]*10+s[1]){
		b[1] = 1;
		if(((s[2] == 'A' || s[2] == 'B' || s[2] == 'C') && (c == 'A' || c == 'B' || c == 'C')) || ((s[2] == 'D' || s[2] == 'E') && (c == 'D' || c == 'E'))) b[2] = 1;
		if((c == 'A' && s[2] == 'B') || (c == 'B' && (s[2] == 'A' || s[2] == 'C')) || (c == 'C' && s[2] == 'B') || (c == 'D' && s[2] == 'E') || (c == 'E' && s[2] == 'D')) b[3] = 1;
	}
	for(int i = 0; i <= 3; i++){
		cout << b[i];
	}
	return 0;
}
