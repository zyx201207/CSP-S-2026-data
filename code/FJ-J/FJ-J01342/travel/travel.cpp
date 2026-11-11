#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,aa,bb;
char cc,dd;
bool aaa(char x,char y){
	if(x=='A'){
		if(y=='B'||y=='C') return 1;
	}
	else if(x=='B'){
		if(y=='A'||y=='C') return 1;
	}
	else if(x=='C'){
		if(y=='B'||y=='A') return 1;
	}
	else if(x=='D'){
		if(y=='F') return 1;
	}
	else if(x=='F'){
		if(y=='D') return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	aa=b[0]+b[1];
	bb=d[0]+d[1];
	cc=b[2];
	dd=d[2];
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(aa==bb) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(aaa(cc,dd)) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(cc-1==dd||dd-1==cc) cout<<1;
	else cout<<0;
	return 0;
}
