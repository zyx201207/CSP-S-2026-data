#include<bits/stdc++.h>
using namespace std;
bool f(char a,char b){
	if(a>'C'&&b>'C') return 1;
	if(a<='C'&&b<='C') return 1;
	return 0;
}
bool f1(char a,char b){
	if(a>'C'&&b>'C') return 1;
	if(a=='C'&&b=='B') return 1;
	if(a=='B'&&b=='C') return 1;
	if(a=='A'&&b=='B') return 1;
	if(a=='B'&&b=='A') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,x1,x2,s1,s2;
	cin>>c1>>c2>>x1>>x2;
	s1+=c2[0];s2+=x2[0];
	s1+=c2[1];s2+=x2[1];
	if(c1==x1) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s1==s2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(f(c2[2],x2[2])) cout<<"1";
	else{
		cout<<"00";
		return 0;
	} 
	if(f1(c2[2],x2[2])) cout<<"1";
	else cout<<"0";
	return 0;
}
