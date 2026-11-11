#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a1,a2,b1,b2;
char a,b;
string aa,bb;
ll x1,x2,x3,x4;
ll is1(char x,char y){
	if(x=='A'&&y=='B')return 1;
	if(x=='B'&&y=='A')return 1;
	if(x=='C'&&y=='A')return 1;
	if(x=='A'&&y=='C')return 1;
	if(x=='B'&&y=='C')return 1;
	if(x=='C'&&y=='B')return 1;
	if(x=='F'&&y=='D')return 1;
	if(x=='D'&&y=='F')return 1;
	return 0;
}
ll is2(char x,char y){
	if(x=='A'&&y=='B')return 1;
	if(x=='B'&&y=='A')return 1;
	if(x=='B'&&y=='C')return 1;
	if(x=='C'&&y=='B')return 1;
	if(x=='F'&&y=='D')return 1;
	if(x=='D'&&y=='F')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>aa>>b1>>bb;
	a2=aa[1]-'0';
	b2=bb[1]-'0';
	a=aa[2];
	b=bb[2];
	if(a1==b1){
		x1=1;
	}
	cout<<x1;
	if(a2==b2&&x1==1){
		x2=1;
	}
	cout<<x2;
	if(is1(a,b)&&x1==1&&x2==1){
		x3=1;
	}
	cout<<x3;
	if(is2(a,b)&&x1==1&&x2==1&&x3==1){
		x4=1;
	}
	cout<<x4;
	return 0;
}
