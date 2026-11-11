#include<bits/stdc++.h>
using namespace std;
string cr, sr, cx, sx; 
bool b = 0, bb = 0, bbb = 0;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cr;
	cin >> sr;
	cin >> cx;
	cin >> sx;
	if(cr[0] == cx[0] && cr[1] == cx[1]){
		printf("1");
		b = 1;
	}
	else
		printf("0");
		
	if(b && sr[0] == sx[0] && sr[1] == sx[1]){
		printf("1");
		bb = 1;
	}
	else
		printf("0");
		
	int rpos = sr[2] - 'A' + 1;
	int xpos = sx[2] - 'A' + 1;
	if(bb && ((rpos <= 3 && xpos <= 3) || (rpos > 3 && xpos > 3))){
		printf("1");
		bbb = 1;
	}
	else
		printf("0");
		
	if(b && bb && bbb && ((xpos == rpos + 1) || (rpos == xpos + 1)))
		printf("1");
	else
		printf("0");
}
