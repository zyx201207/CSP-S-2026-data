//GZ-J00070 张善之 贵阳市云岩区中天中学 
#include <bits/stdc++.h>
using namespace std ;
#define ll long long
int main () {
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) , cout.tie(0) ;
	string x , y , x2 , y2 ;
	cin >> x >> x2 >> y >> y2 ;
	bool sign2 = false ,f3=false;
	if(x[0]==y[0]&&x[1]==y[1]) cout << 1 ;
	else {
		cout <<"0000";
		return 0 ;
	}
	if(x2[0]==y2[0]&&x2[1]==y2[1]) {cout << 1 ;sign2=true;}
	else cout << 0 ;
	bool sign = false ;
	if(sign2){
		if(x2[2]<='C'&&y2[2]<='C'){cout << 1 ;sign=true;} 
		else if(x2[2]>'C'&&y2[2]>'C'){ cout << 1 ; sign=true ;} 	
	}
	if(sign==false) cout << 0 ;
	if(sign){
		if(x2[2]+1==y2[2]&&x2[2]!='C'&&y2[2]!='D'){cout << 1 ; f3=true ;} 
		else if(x2[2]-1==y2[2]&&x2[2]!='D'&&y2[2]!='C'){cout << 1 ;f3=true;} 
	}
	if(f3==false) cout << 0 ;
	return 0 ;
}

