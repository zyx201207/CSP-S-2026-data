#include<bits/stdc++.h>
using namespace std;
char a,b;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	int n1=0,n2=0,n3=0,n4=0;
	a=c2[2];
	b=c4[2];
	if(c1!=c3){
		cout<<0000;
	}
	if(a>='A'||b<='F'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c3||a>='A'||b<='F'&&a=='D'||b=='F'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c3||a>='A'||b<='F'||a=='A'||b=='C'&&a=='D'||b=='F'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c3||a>='A'||b<='F'||a=='A'||b=='B'&&a=='D'||b=='F'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
