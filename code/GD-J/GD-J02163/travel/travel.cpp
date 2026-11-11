#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string xa,xb,ya,yb ;
	cin >> xa >> xb >> ya >> yb ;
	if(xa!=ya){
		cout << "0000" ;
		return 0;
	}
	if(xb[0]!=yb[0]||xb[1]!=yb[1]){
		cout << "1000" ;
		return 0;
	}
	if((xb[2]=='D'||xb[2]=='F') && (yb[2]=='D'||yb[2]=='F')){
		cout << "1111" ;
		return 0;
	}else if((yb[2]=='A'||yb[2]=='B'||yb[2]=='C') && (xb[2]=='A'||xb[2]=='B'||xb[2]=='C')){
		if(xb[2]=='B'||yb[2]=='B'){
			cout << "1111" ;
			return 0;
		}else{
			cout << "1110" ;
			return 0;
		}
	}else{
		cout << "1100" ;
		return 0;
	}
} 
