#include<bits/stdc++.h>
using namespace std;
long long p;
string st1,st2,st3,st4,x,y;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>st1>>st2>>st3>>st4;
	if(st1==st3) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		x=x+(st2[i]);
	}
	for(int i=0;i<2;i++){
		y=y+(st4[i]);
	}
	if(x==y) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	a=st2[2];
	b=st4[2];
	if(a=='F') a='E';
	if(b=='F') b='E';
	if(a=='A'||a=='B'||a=='C') p=1;
	if(a=='D'||a=='E') p=2;
	if(p==1){
		if(b=='A'||b=='B'||b=='C'){
			cout<<"1";
		}
		else{
			cout<<"00";
			return 0;
		}
		if(abs(a-b)==1&&(a!='C'||a!='D')&&(b!='C'||b!='D')){
			cout<<"1";
		}
		else{
			cout<<"0"; 
		}
	}
	if(p==2){
		if(b=='D'||b=='E'){
			cout<<"1";
		}
		else{
			cout<<"00";
			return 0;
		}
		if(abs(a-b)==1&&(a!='C'||a!='D')&&(b!='C'||b!='D')){
			cout<<"1";
		}
		else{
			cout<<"0"; 
		}
	}
	return 0;
}
