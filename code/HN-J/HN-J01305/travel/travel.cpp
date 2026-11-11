#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int xc,rc,a1,b1;
	char xz,rz,a,b;
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc){
		cout<<1;
	}
	else{
		cout<<0;
	}
	a1=xz/10;
	b1=rz/10;
	a=xz%10;
	b=rz%10;
	if(rc==xc&&a1==b1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(rc==xc&&a1==b1&&a<='C'&&b<='C'){
		cout<<1;
	}
	else if(rc==xc&&a1==b1&&a>'c'&&b>'C'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	cout<<1;
	return 0;
}
