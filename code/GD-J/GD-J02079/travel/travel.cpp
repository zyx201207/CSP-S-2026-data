#include<bits/stdc++.h>
using namespace std;
string s[4];
int a,b,c,d;
char bb,dd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	a = (s[0][0]-'0')*10 + s[0][1];
	b = (s[1][0]-'0')*10 + s[1][1];
	bb = s[1][2];
	c = (s[2][0]-'0')*10 + s[2][1];
	d = (s[3][0]-'0')*10 + s[3][1];
	dd = s[3][2];
	if(a==c){
		if(b==d){
			if(bb=='D'&&dd=='F'||dd=='D'&&bb=='F') cout << "1111";
			else if (bb-'A'<=2&&dd-'A'<=2){
				if(abs(bb-'A'-(dd-'A'))<=1) cout << "1111";
				else cout << "1110";
			}
			else cout << "1100";
		}else cout << "1000";
	}else cout << "0000";
	return 0;
} 
