#include<bits/stdc++.h>
using namespace std;

string x,y;
string a,b;
int seat1=0,seat2=0;
char n,m;


void f(){
	if (seat1==seat2){
		if((n=='A' && m=='B') || (n=='B' && m=='C') || (n=='D' && m=='F')){
			cout << "1"; 
		}
		else if((m=='A' && n=='B') || (m=='B' && n=='C') || (m=='D' && n=='F')){
			cout << "1"; 
		}
		else {
			cout << "0";
		}
	}
	
	else {
		cout << "0";
	}
}

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> x >> a >> y >> b;
	
	seat1 = a[0]-'0';
	seat1 = seat1*10+(a[1]-'0');
	seat2 = b[0]-'0';
	seat2 = seat2*10+(b[1]-'0');
	n=a[2];
	m=b[2];
	if(x==y){
		cout << "1";
		if(seat1==seat2){
			cout << "1";
			if (((n<='C' && n>='A') && (m<='C' && m>='A')) || ((n=='D' || n=='F') && (m=='D' || m=='F'))){
				cout << "1";
			}
			else{
				cout << "0";
			}
		}
		else {
			cout << "00";
		}
	}
	else{
		cout << "000";
	}
	f();
	return 0;
}
