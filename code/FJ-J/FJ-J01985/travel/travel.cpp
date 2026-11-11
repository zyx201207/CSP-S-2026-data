#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool pd(char xp,char xq){
	if((xp=='A'||xp=='B'||xp=='C')&&xq!='D'&&xq!='F')
		return 1;
	else{
		if(xp=='D'&&xq=='F')
			return 1;
		if(xp=='F'&&xq=='D')
			return 1;
	}
	return 0;
}
bool chk(char kp,char kq){
	if(abs(kp-kq)==1){
		if(kp!='C'&&kp!='D'&&kq!='C'&&kq!='D')
			return 1;
	}
	else if(kp=='F'&&kq=='D')
		return 1;
	else if(kp=='D'&&kq=='F')
		return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	string x=s1.substr(0,2);
	string y=s2.substr(0,2);
	char p=s1[2],q=s2[2];
	if(c1==c2)
		cout<<1;
	else{
		cout<<"0000";
		exit(0);
	}if(x==y)
		cout<<1;
	else{
		cout<<"000";
		exit(0);
	}if(pd(p,q))
		cout<<1;
	else{
		cout<<"00";
		exit(0);
	}if(chk(p,q))
		cout<<1;
	else 
		cout<<0;
	return 0;
}