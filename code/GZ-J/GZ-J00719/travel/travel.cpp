//GZ-J00719 ×ñÒåÒ»ÖĞ ÆÑ½ÜºÀ 
#include <bits/stdc++.h>
using namespace std;
int a1,c1,b1,c2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a1>>a>>c2>>b1>>b;
	if(c1==c2){
		cout<<"1";
		if(a1==b1){
		cout<<"1";
		if(a>='D'&&b>='D')
		cout<<"11";
		if(a<='C'&&b<='C'){
		cout<<"1";
		if(a=='B'||b=='B')
		cout<<"1";
		else cout<<"0";
		}else cout<<"00";
	}else cout<<"000";
	}else cout<<"0000";
	return 0; 
}

