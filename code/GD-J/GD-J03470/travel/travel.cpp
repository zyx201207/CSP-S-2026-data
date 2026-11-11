#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(char a,char b){
	if(a<='C'&&b<='C') return 1;
	if(a>='D'&&b>='D') return 1;
	return 0;
}
bool check2(char a,char b){
	if(a>b) swap(a,b);
	if(a=='A'&&b=='B') return 1;
	if(a=='B'&&b=='C') return 1;
	if(a=='D'&&b=='F') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0";
	string row1=s1.substr(0,2),row2=s2.substr(0,2);
	if(c1==c2&&row1==row2) cout<<"1";
	else cout<<"0";
	if(c1==c2&&row1==row2&&check(s1[2],s2[2])) cout<<"1";
	else cout<<"0";
	if(c1==c2&&row1==row2&&check(s1[2],s2[2])&&check2(s1[2],s2[2])) cout<<"1";
	else cout<<"0";
	return 0;
} 
