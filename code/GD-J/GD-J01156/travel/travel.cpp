#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2, c3, c4;
	char s1, s2;
	string s;
	getline(cin, s);
	c1 = (s[0]-'0')*10+(s[1]-'0');
	c2 = (s[7]-'0')*10+(s[8]-'0');
	if(c1 == c2) cout << 1;
	else cout << 0;
	c3 = (s[3]-'0')*10+(s[4]-'0');
	c4 = (s[10]-'0')*10+(s[11]-'0');
	if(c1 == c2 && c3 == c4) cout << 1;
	else cout << 0;
	if(c1 == c2 && c3 == c4){
		if(s[5] == 'E' && s[12] == 'D' || s[5] != 'E' && s[12] != 'D'||s[12] == 'E' && s[5] == 'D'){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		cout << 0;
	}
	if(c1 == c2&& c3 == c4){
		if(s[5]=='A'&&s[12]=='B'||s[5]=='B'&&s[12]=='C'||s[5]=='E'&&s[12]=='D'||s[12]=='A'&&s[5]=='B'||s[12]=='B'&&s[5]=='C'||s[12]=='E'&&s[5]=='D'){
			cout<<1;
		}else {
			cout<<0;
		}
	}else{
		cout << 0;
	}
	return 0;
}
