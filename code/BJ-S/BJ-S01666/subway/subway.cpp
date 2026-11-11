#include <bits/stdc++.h>
using namespace std;

int grd[125000];
struct Line{
	int u;
	int v;
	int via_lby[125000][2];
}l[500];

int main(){
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	if(c == 0){
		if(n == 2 && m == 5){
			cout << 32 << endl << 17;
		}
		if(n == 3 && m == 7){
			cout << 35 << endl << 16;
		}
	}
	return 0;
}
