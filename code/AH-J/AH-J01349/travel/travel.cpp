#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string xc,rc;
    char x1,r1,x2,r2,x3,r3;
	cin >>xc>>x1>>x2>>x3>>rc>>r1>>r2>>r3;
	if(xc==rc){cout <<1;
	if(x1==r1&&x2==r2){cout <<1;
	if(((x3=='A'||x3=='B'||x3=='C')&&(r3=='A'||r3=='B'||r3=='C'))||(x3=='E'||x3=='F')&&(x2=='E'||x2=='F')){
	cout <<1;
	}else{
	cout <<0;
	}
	if((x3=='A'&&r3=='B')||(x3=='B'&&r3=='A')||(x3=='B'&&r3=='C')||(x3=='C'&&r3=='B')||(x3=='E'&&r3=='F')||(x3=='F'&&r3=='E')){
	cout <<1;
	}else{
	cout <<0;
	}
	}else{cout <<"000";}
	
	}else{cout <<"0000";}
	return 0;
} 
