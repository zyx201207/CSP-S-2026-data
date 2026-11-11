#include<bits/stdc++.h>
using namespace std;
bool isVaild(char a,char b){
	if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')) return true;
	if((a=='D'||a=='F')&&(b=='D'||b=='F')) return true;
	return false;
}
bool isVaild2(char a,char b){
	if(a=='A'&&b=='B') return true;
	if(a=='B'&&b=='A') return true;
	if(a=='B'&&b=='C') return true;
	if(a=='C'&&b=='B') return true;
	if(a=='D'&&b=='F') return true;
	if(a=='F'&&b=='D') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,res="";
	cin>>a>>b>>c>>d;
	bool k=isVaild(b[2],d[2]),k2=isVaild2(b[2],d[2]);
	if(a==c) res+='1';
	else res+='0';
	if(a==c&&b.substr(0,2)==d.substr(0,2)) res+='1';
	else res+='0';
	if(a==c&&b.substr(0,2)==d.substr(0,2)&&k) res+='1';
	else res+='0';
	if(a==c&&b.substr(0,2)==d.substr(0,2)&&k&&k2) res+='1';
	else res+='0';
	cout<<res;
	return 0;
} 
