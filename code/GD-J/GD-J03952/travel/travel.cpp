#include<bits/stdc++.h>
using namespace std;

string cr,sr,cx,sx;
int rzero,ralpha,xzero,xalpha;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cr >> sr >> cx >> sx;
	rzero=(sr[0]-'0')*10+sr[1]-'0';
	ralpha=sr[2]-'A'+1;
	xzero=(sx[0]-'0')*10+sx[1]-'0';
	xalpha=sx[2]-'A'+1;
	
	bool a=0,b=0,c=0;
	if(cr==cx){
		cout << 1;
		a=1;
	}
	else cout << 0;
	if(a && rzero==xzero){
		cout << 1;
		b=1;
	}
	else cout << 0;
	if(b && ((ralpha>3 && xalpha>3) || (ralpha<=3 && xalpha<=3))){
		cout << 1;
		c=1;
	}
	else cout << 0;
	if(c && ((abs(ralpha-xalpha)==1 && ralpha<=3) || (abs(ralpha-xalpha)==2 && ralpha>3))) cout << 1;
	else cout << 0;
	
	return 0;
}

