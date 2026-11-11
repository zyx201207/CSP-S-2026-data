#include<bits/stdc++.h>
using namespace std;
using ll=long long;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else {
		cout<<"0000";
	}
	string x=s1[0]+"";
	x=x+(char)(s1[1]);
	string y=s2[0]+"";
	y=y+(char)(s2[1]);
	if(x==y)cout<<1;
	else {
		cout<<"000";
	}
	char a=s1[2];
	char b=s2[2];
	if(
	(a=='D'||a=='F')&&(b=='D'||b=='F')
	){
		cout<<1;
	}
	else if(
	(a=='A'&&(b=='B'||b=='C'))||
	(a=='B'&&(b=='A'||b=='C'))||
	(a=='C'&&(b=='A'||b=='B'))
	){
		cout<<1;
	}
	else {
		cout<<"00";
		return 0;
	}
	if((a=='A'&&b=='B')||
	   (a=='B'&&(b=='A'||b=='C'))||
	   (a=='C'&&b=='B')
	){
		cout<<1;
	}
	else if((a=='D'&&b=='F')||
			(a=='F'&&b=='D')
	){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
