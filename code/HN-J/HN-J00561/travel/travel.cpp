#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}
	else cout<<"0";
	if(b[0]==d[0]&&b[1]==d[1]&&a==c){
		cout<<"1";
	}
	else cout<<"0";
	if(b[0]==d[0]&&b[1]==d[1]&&a==c){
		if(b[2]=='A'){
			if(d[2]=='B') cout<<"11";
			if(d[2]=='C') cout<<"10";
			if(d[2]=='D') cout<<"00";
			if(d[2]=='F') cout<<"00";
		}
		if(b[2]=='B'){
			if(d[2]=='A') cout<<"11";
			if(d[2]=='C') cout<<"11";
			if(d[2]=='D') cout<<"00";
			if(d[2]=='F') cout<<"00";
		}
		if(b[2]=='C'){
			if(d[2]=='A') cout<<"10";
			if(d[2]=='B') cout<<"11";
			if(d[2]=='D') cout<<"00";
			if(d[2]=='F') cout<<"00";
		}
		if(b[2]=='D'){
			if(d[2]=='A') cout<<"00";
			if(d[2]=='B') cout<<"00";
			if(d[2]=='C') cout<<"00";
			if(d[2]=='F') cout<<"11";
		}
		if(b[2]=='F'){
			if(d[2]=='A') cout<<"00";
			if(d[2]=='B') cout<<"00";
			if(d[2]=='C') cout<<"00";
			if(d[2]=='D') cout<<"11";
		}
	}
	else cout<<"00";
	return 0;
}
// 湖南省株洲市第二中学
// Luogu 1226884 1251088
//  No.2 Middle School of Zhuzhou Hunan
// 100pts? 
