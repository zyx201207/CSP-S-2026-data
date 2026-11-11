#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	int x=0,y=0,z=0;
	if(a1==a2){
		cout<<1;
		x=1;
	}
	else cout<<0;
	if(b1[0]==b2[0]&&x==1&&b1[1]==b2[1]){
		cout<<1;
		y=1;
	}
	else cout<<0;
	if(b1[2]<='C'&&b2[2]<='C'&&x==1&&y==1||b1[2]>'C'&&b2[2]>'C'&&x==1&&y==1){
		cout<<1;
		z=1;
	}
	else cout<<0;
	if(b1[2]+1==b2[2]&&x+y+z==3||b1[2]-1==b2[2]&&x+y+z==3){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
