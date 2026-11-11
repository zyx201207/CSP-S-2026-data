#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
char a,b;
int cc1,cc2,ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=s1[2];
	b=s2[2];
	cc1=(c1[0]-'0')*10+c1[1]-'0';
	cc2=(c2[0]-'0')*10+c2[1]-'0';
	ss1=(s1[0]-'0')*10+s1[1]-'0';
	ss2=(s2[0]-'0')*10+s2[1]-'0';
	if(cc1==cc2)cout<<1;
	else cout<<0;
	if(cc1==cc2&&ss1==ss2)cout<<1;
	else cout<<0;
	bool s=0;
	if(cc1==cc2&&ss1==ss2){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C'){
			cout<<1;
			s=1;
		}
	}
	if(a=='D'||a=='F'){
		if(b=='D'||b=='F'){
			cout<<1;
			s=1;
		}
	}
	}
	if(!s)cout<<0;
	s=0;
	if(cc1==cc2&&ss1==ss2){
		if(a=='A'&b=='B'){
			s=1;
		}
		if(a=='B'&b=='A'){
			s=1;
		}
		if(a=='B'&b=='C'){
			s=1;
		}
		if(a=='C'&b=='B'){
			s=1;
		}
		if(a=='D'&b=='F'){
			s=1;
		}
		if(a=='F'&b=='D'){
			s=1;
		}	
	}
	if(s)cout<<1;
	else cout<<0;
	
}

