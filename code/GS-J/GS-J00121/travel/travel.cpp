#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cc1,ss2,cc2,ss1;
	cin >> cc1 >> ss1 >> cc2 >> ss2;
	if(cc1[0]==cc2[0]&&cc1[1]==cc2[1]){
		cout << "1";
	}
	else{cout << "0000";return 0;
	}
	if(ss1[0]==ss2[0]&&ss1[1]==ss2[1]){
		cout << "1";
	}
	else{
		cout << "000";return 0;
	}
	if(ss1[2]<='C'&&ss2[2]<='C'){
		cout << "1";
	}
	else if((ss1[2]=='D'&&ss2[2]=='F')||(ss1[2]=='F'&&ss2[2]=='D')){
		cout << "11";return 0;
	}
	else{
		cout << "00";return 0;
	}
	if((ss1[2]=='A'&&ss2[2]=='B')||(ss1[2]=='B'&&ss2[2]=='C')){
		cout << "1";
	}
	else if((ss2[2]=='A'&&ss1[2]=='B')||(ss2[2]=='B'&&ss1[2]=='C')){
		cout << "1";
	}
	else {
		cout << "0";}
	return 0;
}
