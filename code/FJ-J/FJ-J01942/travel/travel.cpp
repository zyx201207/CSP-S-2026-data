#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string a1,a2,b1,b2;
char a3,b3;
int x=1;
bool ce(){
	if(a3<='C'&&b3<='C'){
		return 1;
	}if(a3>'C'&&b3>'C'){
		x=2;
		return 1;
	}return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	a1=a;a2=b[0]+b[1];a3=b[2];
	b1=c;b2=d[0]+d[1];b3=d[2];
	if(a1==b1){cout<<1;}
	else{cout<<0;x=0;}
	if(x&&a2==b2){cout<<1;}
	else{cout<<0;x=0;}
	if(x&&ce()){cout<<1;}
	else{cout<<0;x=0;}
	if(x==2||(x==(a3-b3))){cout<<1;}
	else{cout<<0;}
}
