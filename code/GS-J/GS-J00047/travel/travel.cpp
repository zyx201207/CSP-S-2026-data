#include<bits/stdc++.h>
using namespace std;
bool s1(char a,char b){
	if(a=='A'&&b=='B' || a=='B'&&b=='A' || a=='A'&&b=='C' || a=='C' && b=='A' || a=='B'&&b=='C' || a=='C'&&b=='B') return 1;
	else if(a=='D'&&b=='F' || a=='F'&&b=='D') return 1;
	else return 0;
}
bool s2(char a,char b){
	if(a=='A'&&b=='B' || a=='B'&&b=='A' || a=='B'&&b=='C' || a=='C'&&b=='B') return 1;
	else if(a=='D'&&b=='F' || a=='F'&&b=='D') return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)cout<<1;
	else cout<<0;
	if(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1]) cout<<1;
	else cout<<0;
	bool bx = 0;
	if(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1] && s1(a2[2],b2[2])){
		cout<<1;
		bx = 1;
	}else{
		cout<<0;
	}
	if(bx && s2(a2[2],b2[2])) cout<<1;
	else cout<<0;
	return 0;
}
