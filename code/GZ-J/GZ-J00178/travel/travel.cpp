//GZ-J00178 观山湖中学 陈辰 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	string a,b,c,d;
	cin >>a>>b>>c>>d;
	if (a!=c){
		cout <<"0000";
		return ; 
	}
	cout <<1;
	if (b[0]!=d[0]||b[1]!=d[1]){
		cout <<"000";
		return ;
	}
	cout <<1;
	if (b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if (d[2]!='A'&&d[2]!='B'&&d[2]!='C'){
			cout <<"00";
			return ;
		}
		cout <<1;
	}
	else{
		if (d[2]!='D'&&d[2]!='F'){
			cout <<"00";
			return ;
		}
		cout <<"11";
		return ;
	}
	if ((d[2]=='A'||d[2]=='C')&&(b[2]=='A'||b[2]=='C')){
		cout <<0;
		return ;
	}
	cout <<1;
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
	//cin >>T;
	while(T--){
		solve();
	}
	return 0;
}
