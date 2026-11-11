#include <bits/stdc++.h>
using namespace std;

string s1,s2,s3,s4;
int a=0,b=0,c=0,d=0;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	for (int i=0;i < 2;i++){
		a=a*10;
		a+=(s1[i]-'0');
	}
	for (int i=0;i < 2;i++){
		b=b*10;
		b+=(s2[i]-'0');
	}
	for (int i=0;i < 2;i++){
		c=c*10;
		c+=(s3[i]-'0');
	}
	for (int i=0;i < 2;i++){
		d=d*10;
		d+=(s4[i]-'0');
	}
	if(a==c){
		cout << 1;
	}
	else {cout << "0000"; return 0;}
	if(b==d){
		cout << 1;
	}
	else{ cout << "000"; return 0;}
	if (s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
			if(s4[2]=='A' || s4[2]=='B' || s4[2]=='C'){
				cout << 1;
			}
			else {cout << "00"; return 0;}
	}
	if (s2[2]=='D' || s2[2]=='F'){
			if(s4[2]=='D' || s4[2]=='F'){
				cout << 1;
			}
			else {cout << "00"; return 0;}
	}
	if (s2[2]=='A' && s4[2]=='B'){
		cout << 1; return 0;
	}
	if (s2[2]=='B' && s4[2]=='A'){
		cout << 1; return 0;
	}
	if (s2[2]=='B' && s4[2]=='C'){
		cout << 1; return 0;
	}
	if (s2[2]=='C' && s4[2]=='B'){
		cout << 1; return 0;
	}
	if (s2[2]=='D' && s4[2]=='F'){
		cout << 1; return 0;
	}
	if (s2[2]=='F' && s4[2]=='D'){
		cout << 1; return 0;
	}
	cout << 0;
	return 0;
}
