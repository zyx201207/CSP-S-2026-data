#include <bits/stdc++.h>
using namespace std;

int main(){
	
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);

int c1,c3;
string c2,c4; 
cin>>c1>>c2>>c3>>c4;
int an1=0,an2=0,an3=0,an4=0;
int a,b;
if(c1==01||c1==16||c3==01||c3==16){
	return 0;
}
if(c2[2]=='A'){
	a=1;
}
if(c2[2]=='B'){
	a=2;
}
if(c2[2]=='C'){
	a=3;
}
if(c2[2]=='D'){
	a=4;
}
if(c2[2]=='E'){
	a=5;
}
if(c4[2]=='A'){
	b=1;
}
if(c4[2]=='B'){
	b=2;
}
if(c4[2]=='C'){
	b=3;
}
if(c4[2]=='D'){
	b=4;
}
if(c4[2]=='E'){
	b=5;
}
if(c1==c3){
	an1=1;
}
if(an1==1){
	if(c2[0]==c4[0]&&c2[1]==c4[1]){
		an2=1;
	}
	if(an2==1){
		if(a<=3&&b<=3){
			an3=1;
		}
		else if(a>3&&b>3){
			an3=1;
		}
		else{
			an3=0;
		}
		if(an3==1){
			if(a+1==b||a-1==b){
				an4=1;
			}
		}	 
	}
}


cout<<an1<<an2<<an3<<an4;
return 0;
}
