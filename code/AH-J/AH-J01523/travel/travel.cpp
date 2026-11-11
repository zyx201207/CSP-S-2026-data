#include<bits/stdc++.h>
using namespace std;
string a1,b1,c1,d1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>c1>>d1;
	if(a1!=c1){
		cout<<"0000";
		return 0;
	}
	if(a1==c1&&(b1[0]!=d1[0]||b1[1]!=d1[1])){
		cout<<"1000";
		return 0;
	}
	if(a1==c1&&b1[0]==d1[0]&&b1[1]==d1[1]&&(b1[2]<='C'&&d1[2]>'C')||(b1[2]>'C'&&d1[2]<='C')){
		cout<<"1100";
		return 0;
	}
	if(a1==c1&&b1[0]==d1[0]&&b1[1]==d1[1]&&((b1[2]<='C'&&d1[2]<='C')||(b1[2]>'C'&&d1[2]>'C'))&&abs(b1[2]-d1[2])!=1){
		cout<<"1110";
		return 0;
	}
	if(a1==c1&&b1[0]==d1[0]&&b1[1]==d1[1]&&((b1[2]<='C'&&d1[2]<='C')||(b1[2]>'C'&&d1[2]>'C'))&&abs(b1[2]-d1[2])==1){
		cout<<"1111";
		return 0;
	}
	return 0;
}
