#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2;
	string b1,b2;
	cin >>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout <<"1";
	}else {
		cout <<"0000";
		return 0;
	}
	if(a2[0]-'0'==b2[0]-'0'&&a2[1]-'0'==b2[1]-'0'&&a2[2]!=b2[2]){
		cout <<"1";
	}else {
		cout <<"0";
	}
	if((('A'<=a2[2]&&a2[2]<='C'&&'A'<=b2[2]&&b2[2]<='C')||('D'<=a2[2]&&a2[2]<='F'&&'D'<=b2[2]&&b2[2]<='F'))&&a2[0]-'0'==b2[0]-'0'&&a2[1]-'0'==b2[1]-'0'){
		cout <<"1";
	}else {
		cout <<"0";
	}
	if((a2[2]-b2[2]==1||b2[2]-a2[2]==1)&&(('A'<=a2[2]&&a2[2]<='C'&&'A'<=b2[2]&&b2[2]<='C')||('D'<=a2[2]&&a2[2]<='F'&&'D'<=b2[2]&&b2[2]<='F'))&&a2[0]-'0'==b2[0]-'0'&&a2[1]-'0'==b2[1]-'0'){
		cout <<"1";
	}else {
		cout <<"0";
	}
	return 0;
}
