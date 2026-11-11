#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,a1,c=0;
	string b1,b;
	cin>>a>>b>>a1>>B1;
	if(a==a1){
		cout<<1;
		c++;
	}else{
		cout<<0;
	}if(b[0]-'0'==b1[0]-'0' && b[1]-'0'==b1[1]-'0'&&c==1){
		cout<<1;
		c++;
	}else{
		cout<<0;
	}if(b[2]=='A'||b[2]=='B'||b[2]=='C'&&b1[2]=='A'||b1[2]=='B'||b1[2]=='C'&&c==2){
		cout<<1;
	}
	else if(b[2]=='E'||b[2]=='D'&&b[2]=='D'||b[2]=='E'&&c==2){
		cout<<1;
	}
	else{
		cout<<0;
	}if(c==3&&b[2]=='A'&&b1[2]=='B'||b[2]=='B'&&b1[2]=='C'||b[2]=='D'&&b1[2]=='E'||b[2]=='E'&&b1[2]=='D'||b[2]=='B'&&b1[2]=='A'||b[2]=='C'&&b1[2]=='B'||){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}


