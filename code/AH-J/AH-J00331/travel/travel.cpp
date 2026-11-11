#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int check1(){
	if(b[2]>'C'&&d[2]>'C')return 1;
	if(b[2]<'D'&&d[2]<'D')return 1;
	return 0;
}
int check2(){
	if(check1()==0)return 0;
	if(b[2]=='A'&&d[2]=='B')return 1;
	if(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))return 1;
	if(b[2]=='C'&&d[2]=='B')return 1;
	if(b[2]=='D'&&d[2]=='F')return 1;
	if(b[2]=='F'&&d[2]=='D')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		puts("0000");
		return 0;
	}else cout<<1;
	if(b[0]!=d[0]||b[1]!=d[1]){
		puts("000");
		return 0;
	}else cout<<1;
	cout<<check1()<<check2();
}
