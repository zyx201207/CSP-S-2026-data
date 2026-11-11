#include <bits/stdc++.h>
using namespace std;
struct node{
	int c;
	string s;
	int car;
	int line;
	string side;
	char seat;
}a, b;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a.c >> a.s >> b.c >> b.s;
	a.car = a.c;
	b.car = b.c;
	a.seat = a.s[2];
	b.seat = b.s[2];
	if(a.s[0] == '0') a.line = a.s[1] - '0';
	else a.line = ((a.s[0] - '0') * 10 + (a.s[1] - '0'));
	if(b.s[0] == '0') b.line = b.s[1] - '0';
	else b.line = ((b.s[0] - '0') * 10 + (b.s[1] - '0'));
	if(a.seat == 'A' || a.seat == 'B' || a.seat == 'C') a.side = "left";
	else a.side = "right";
	if(b.seat == 'A' || b.seat == 'B' || b.seat == 'C') b.side = "left";
	else b.side = "right";
	if(a.car == b.car){
		cout << '1';
		if(a.line == b.line){
			cout << '1';
			if(a.side == b.side){
				cout << '1';
				if(a.side == "right"){
					if((a.seat == 'D' && b.seat == 'F') || (a.seat == 'F' && b.seat == 'D')){
						cout << '1';
					}else{
						cout << '0';
					}
				}else{
					if((a.seat == 'A' && b.seat == 'B') || (a.seat == 'B' && b.seat == 'A') || (a.seat == 'B' && b.seat == 'C') || (a.seat == 'C' && b.seat == 'B')){
						cout << '1';
					}else{
						cout << '0';
					}
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
} 
