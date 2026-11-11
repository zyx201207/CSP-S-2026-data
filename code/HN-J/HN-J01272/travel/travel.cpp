#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool x=0;
	if(a==c){
		cout <<1;
		x=1;
	}
	else {
		cout<<0;
		x=0;
	}
	if(b[0]==d[0] && b[1]==d[1] && x==1){
		cout <<1;
		x=1;
	}
	else {
		cout<<0;
		x=0;
	}
	if(b[2] >='C' && d[2]>='C'&& x==1){
		cout <<1;
		x=1;
	}
	else if(b[2] <='D' && d[2] <='D'&& x==1){
		cout <<1;
		x=1;
	}
	else {
		cout<<0;
		x=0;
	}if((b[2]-d[2]==1 || d[2]-b[2]==1) && x==1){
		cout <<1;
		x=1;
	}
	else {
		cout<<0;
		x=0;
	}
	return 0;
}
