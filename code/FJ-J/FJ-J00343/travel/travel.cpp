#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string rc,rs,xc,xs;
	cin >> rc >> rs >> xc >> xs ;
	if((rc=="01"||rc=="16")||(xc=="01"||xc=="16")){
		cout << "0000" << '\n';
		return 0 ;
	}
	if(rc!=xc){
		cout << "0000" << '\n';
		return 0;
	}else cout << 1 ;
	if(rs[0]+rs[1]==xs[0]+xs[1]){
		cout << 1 ;
	}else{
		cout << "000"<< '\n' ;
		return 0;
	}
	if((rs[2]<='C'&&xs[2]<='C')||(rs[2]>'C'&&xs[2]>'C')){
		cout << 1 ;
	}else{
		cout << "00" << '\n' ;
		return 0;
	}
	if(rs[2]+1==xs[2]){
		if(rs[2]!='C'&&xs[2]!='D') cout << 1 <<'\n';
		else cout << 0 << '\n';
	}
	else cout << 0 << '\n';
	return 0 ;
}
