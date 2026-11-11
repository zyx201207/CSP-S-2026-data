#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> cx >> sx >> cy >> sy;
	bool a = 0,b = 0,c = 0,d = 0;
	if(cx == cy) a = 1;
	string t1 = sx.substr(0,2);
	string t2 = sy.substr(0,2);
	if(a && t1 == t2) b = 1;
	if(b){
		if((sx[2] == 'D' && sy[2] == 'F') || (sx[2] == 'F' && sy[2] == 'D')) c = 1;
		else if((sx[2] == 'A' && sy[2] == 'B') || (sx[2] == 'B' && sy[2] == 'A')) c = 1;
		else if((sx[2] == 'A' && sy[2] == 'C') || (sx[2] == 'C' && sy[2] == 'A')) c = 1;
		else if((sx[2] == 'B' && sy[2] == 'C') || (sx[2] == 'C' && sy[2] == 'B')) c = 1;
	}
	if(c){
		if((sx[2] == 'D' && sy[2] == 'F') || (sx[2] == 'F' && sy[2] == 'D')) d = 1;
		else if((sx[2] == 'A' && sy[2] == 'B') || (sx[2] == 'B' && sy[2] == 'A')) d = 1;
		else if((sx[2] == 'B' && sy[2] == 'C') || (sx[2] == 'C' && sy[2] == 'B')) d = 1;
	}
	cout << a << b << c << d;
	return 0;
}
