#include <bits/stdc++.h>
using namespace std;
string a , b , c , d;
int f2(){
	if(b[2]=='A'&&d[2]=='B')return 1;
	else if(b[2]=='A'&&d[2]=='C')return 1;
	else if(b[2]=='B'&&d[2]=='A')return 1;
	else if(b[2]=='B'&&d[2]=='C')return 1;
	else if(b[2]=='C'&&d[2]=='A')return 1;
	else if(b[2]=='C'&&d[2]=='B')return 1;
	else if(b[2]=='F'&&b[2]=='D') return 1;
	else if(b[2]=='D'&&b[2]=='F') return 1;	
	else return 0;
}
int f3(){
	char aa = b[2] , bb=d[2];
	if(aa=='A'&&bb=='B') return 1;
	else if(aa=='B'&&bb=='C') return 1;
	else if(aa=='D'&&bb=='F') return 1;
	else if(aa=='F'&&bb=='D') return 1;
	else if(aa=='C'&&bb=='B') return 1;
	else if(aa=='B'&&bb=='A') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>a>>b>>c>>d;
	if(a==c) cout <<1;
	else cout <<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]) cout <<1;
	else cout <<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&f2()) cout <<1;
	else cout <<0;	
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&f3()) cout <<1;	
	else cout <<0;
	return 0; 
} 
