#include<bits/stdc++.h>
using namespace std;
char c1,c2;
long long a1,a2,b1,b2,b3,b4,d1,d2,x,o;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> d1 >>c1 >> a2 >> d2 >> c2;
	if(a1 == a2){
		b1 = 1;
	}
	if(d1== d2){
		b2 = 1;
	}
	x = c1 * 1;

	o = c2 * 1;
	if(d1== d2 && (65 <= x && x <= 67 &&65 <= o && o <= 67 ||68 <= o && o <= 69 &&68 <= x && x <= 69)){
		b3 = 1;
	}
	if(d1== d2 && x + 1 == o && (65 <= x && x <= 67 &&65 <= o && o <= 67 ||68 <= o && o <= 69 &&68 <= x && x <= 69)){
		b4 = 1;
	}
	cout << b1 << b2 << b3 << b4;
}

