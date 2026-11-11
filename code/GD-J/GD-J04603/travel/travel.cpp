#include<bits/stdc++.h>
using namespace std;

string x , y , xx , yy;
int a = 0, b = 0, c = 0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> x >> xx >> y >> yy;
	//1
	if(x == y){
		cout << 1;
	}
	else{
		cout << 0;
		a = 1;
	}
	//2
	if(xx[0] == yy[0] && xx[1] == yy[1] && a == 0){
		cout << 1;
	}
	else{
		cout << 0;
		b = 1;
	}
	//3
	if(a == 0 && b == 0){
		if(xx[2] <= 'C' && yy[2] <= 'C' && xx[2] != yy[2]){
			cout << 1;
			if(xx[2] + 1 == yy[2] || xx[2] - 1 == yy[2]){
				c = 1;
			}
		}
		else if(xx[2] > 'C' && yy[2] > 'C' && xx[2] != yy[2]){
			cout << 1;
			if(xx[2] + 2 == yy[2] || xx[2] - 2 == yy[2]){
				c = 1;
			}
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0;
	}
	//4
	if(c == 1){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
