#include<bits/stdc++.h>
using namespace std;
int c1,c2,f1=0,f2=0,f3=0,f4=0;
string s1,s2;
bool ss(char a,char b){
	if(a=='A'&&(b=='B'||b=='C')||
	a=='B'&&(b=='A'||b=='C')||
	a=='C'&&(b=='A'||b=='B')||
	a=='D'&&b=='F'||
	a=='F'&&b=='D'){
		return true;
	}return false;
}
bool ss2(char a,char b){
	if(a=='A'&&b=='B'||
	a=='B'&&(b=='A'||b=='C')||
	a=='C'&&b=='B'||
	a=='D'&&b=='F'||
	a=='F'&&b=='D'){
		return true;
	}return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		f1=1;
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(f1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		f2=1;
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(f1&&f2&&ss(s1[2],s2[2])){
		f3=1;
		cout<<1;
	}else{
		cout<<0 ;
	}
	
	if(f1&&f2&&f3&&ss2(s1[2],s2[2])){
		f4=1;
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
