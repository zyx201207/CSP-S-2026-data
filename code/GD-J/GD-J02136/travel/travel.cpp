#include<bits/stdc++.h>
using namespace std;

string car1, car2;
string seat1, seat2;
int s1, s2;
bool w1, w2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> car1 >> seat1 >> car2 >> seat2;
	if(car1==car2) cout << 1;
	else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]) cout << 1;
	else{
		cout << 0 << 0 << 0;
		return 0;
	}
	switch(seat1[2]){
		case 'A': w1=1, s1=1; break;
		case 'B': w1=1, s1=2; break;
		case 'C': w1=1, s1=3; break;
		case 'D': w1=0, s1=1; break;
		case 'F': w1=0, s1=2;
	}
	switch(seat2[2]){
		case 'A': w2=1, s2=1; break;
		case 'B': w2=1, s2=2; break;
		case 'C': w2=1, s2=3; break;
		case 'D': w2=0, s2=1; break;
		case 'F': w2=0, s2=2;
	}
	if(w1==w2){
		if(s1-s2==1||s1-s2==-1) cout << 11;
		else cout << 10;
	}
	else{
		cout << 0 << 0;
	}
	return 0;
}
