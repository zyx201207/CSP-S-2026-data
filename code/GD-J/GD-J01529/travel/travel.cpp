#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool ck1(char x,char y){
	if(x>y)swap(x,y);
	if(x<'D'&&y>'C')return 0;
	return 1;
}
bool ck2(char x,char y){
	if(x>y)swap(x,y);
	if(x=='A'&&y=='B')return 1;
	if(x=='B'&&y=='C')return 1;
	if(x=='D'&&y=='F')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(ck1(b[2],d[2]))cout<<1;
			else cout<<0;
			if(ck2(b[2],d[2]))cout<<1;
			else cout<<0;
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
