#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("travel.in","r"stdin);
	//freopen("travel.out","w"stdout);
	cout << 1000;
	string a,b,c,d;
	cin >>a>>b>>c>>d;
	char s=d[3];
	if(a==c){
		if(b[1]==d[1]&&b[2]==d[2]){
			if(s=='A'){
				if(s=='B') cout << 1111;
				else if(s=='C') cout << 1110;
			}
			else if(b[3]=='B'){
				if(s=='A'||s=='C') cout << 1111;
			}
			else if(b[3]=='C'){
				if(s=='B') cout << 1111;
				else if(s=='C') cout << 1110;
			}
			else if(b[3]=='D'){
				if(s=='F') cout << 1111;
			}
			else if(b[3]=='F'){
				if(s=='D') cout << 1111;
			}
			else{
				cout << 1100;
			}
	}
	else cout << 0000;
	return 0;

}}
