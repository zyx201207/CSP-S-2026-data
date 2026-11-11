#include<bits/stdc++.h>
#define I using
#define AK namespace
#define CSP std
I AK CSP;
string n,a,m,b;
bool x(char a,char b){
	if(a=='A'){
		if(b=='B'||b=='C')
			return true;
		else
			return false;
	}
	if(a=='B'){
		if(b=='A'||b=='C')
			return true;
		else
			return false;
	}
	if(a=='C'){
		if(b=='B'||b=='A')
			return true;
		else
			return false;
	}
	if(a=='D'){
		if(b=='E')
			return true;
		else
			return false;
	}
	if(a=='E'){
		if(b=='D')
			return true;
		else
			return false;
	}
}
bool x1(char a,char b){
	if((a=='C'&&b=='D')||(a=='D'&&b=='C')){
		return false;
	}
	else{
		if(a+1==b||a-1==b){
			return true;
		}
		else{
			return false;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m)cout<<"1";
	else cout<<"0";
	if((n==m)&&(a[0]==b[0]&&a[1]==b[1]))cout<<"1";
	else cout<<"0";
	if(((n==m)&&(a[0]==b[0]&&a[1]==b[1]))&&x(a[2],b[2]))cout<<"1";
	else cout<<"0";
	if((((n==m)&&(a[0]==b[0]&&a[1]==b[1]))&&x(a[2],b[2]))&&x1(a[2],b[2]))cout<<"1";
	else cout<<"0";
	return 0;
}



//Thank you CCF! 
//My luogu name:Fat_Catt
//hu guan qwq 

//I want to see myself at Luogu!
//Trick||Treat!
