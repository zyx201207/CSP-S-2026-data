#include <iostream>
using namespace std;
int a[5];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string b, c, s1, s2, d, e;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		a[1] = 1;
	}
	b = s1[0] + s1[1];
	c = s2[0] + s2[1];
	if(b == c){
		a[2] = 1;
	}
	d = s1[2];
	e = s2[2];
	if(a[2] == 1){
		if((d == "A") || (d == "B") || (d == "C")){
			if(e == "A" || e == "B" || e == "C"){
				a[3] = 1;
			}
		}
		if(d == "D" || d == "F"){
			if(e == "D" || e == "F"){
				a[3] = 1;
			}
		}
	}
	if(a[3] == 1){
		a[4] = 1;
		if(d == "A" || d == "C"){
			if(e == "A" || e == "C"){
				a[4] = 0;
			}
		}
	}
	for(int i = 1; i <= 4; i++){
		cout << a[i];
	}
}
