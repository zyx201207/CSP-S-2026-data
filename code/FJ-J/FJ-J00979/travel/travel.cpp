#include<bits/stdc++.h>
using namespace std;
string c1;
string s1;
string c2;
string s2;
char a;
char b;
//int a1;
//int b1;
string a1;	
string b1;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	a=s1[2];
	b=s2[2];
	a1={s1[0],s1[1]};
	b1={s2[0],s2[1]};
	if(a1==b1&&c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a1==b1&&c1==c2&&((a<'D'&&b<'D')||(a=='F'&&b=='D')||(a=='D'&&b=='F'))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&a1==b1&&((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')||(b=='A'&&a=='B')||(b=='B'&&a=='C')||(b=='D'&&a=='F'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
