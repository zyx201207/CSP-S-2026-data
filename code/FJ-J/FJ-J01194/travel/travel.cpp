#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
bool f,ff;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << 1;
		ff=1;
	}
	else{
		cout << 0;
		ff=0;
	}
	
	string pai1=s1.substr(0,2);
	string pai2=s2.substr(0,2);
	
	if(pai1==pai2&&ff){
		cout << 1;
		f=1;
	}
	else{
		cout << 0;
		f=0;
	}

	char seat1=s1[2];
	char seat2=s2[2];
	
	if(f&&(
	(seat1=='A'&&seat2=='B')||
	(seat1=='B'&&seat2=='A')||
	(seat1=='B'&&seat2=='C')||
	(seat1=='C'&&seat2=='B')||
	(seat1=='A'&&seat2=='C')||
	(seat1=='C'&&seat2=='A')||
	(seat1=='D'&&seat2=='F')||
	(seat1=='F'&&seat2=='D'))){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	if(f&&(
	(seat1=='A'&&seat2=='B')||
	(seat1=='B'&&seat2=='A')||
	(seat1=='B'&&seat2=='C')||
	(seat1=='C'&&seat2=='B')||
	(seat1=='D'&&seat2=='F')||
	(seat1=='F'&&seat2=='D'))){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}