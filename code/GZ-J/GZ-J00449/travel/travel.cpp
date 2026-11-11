//GZ-J00449 曾嵩 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
int a,b,c,d;
char R,X;
bool ch_R,ch_X;
bool check_4(char m,char n){
	char R=m,X=n;
	if((R=='A'&&X=='C')||(R=='C'&&X=='A')) return false;
	if((R=='A'&&X=='B')||(R='B'&&X=='A')||(R=='B'&&X=='C')||(R=='C'&&X=='B')||(R=='D'&&X=='F')||(R=='F'&&X=='D'))  return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	a=int(c_1[0]-48)*10+int(c_1[1]-48);
	b=int(c_2[0]-48)*10+int(c_2[1]-48);
	c=int(s_1[0]-48)*10+int(s_1[1]-48);
	d=int(s_2[0]-48)*10+int(s_2[1]-48);
	R=s_1[2],X=s_2[2];
	if(R>='A'&&R<='C') ch_R=true;
	else ch_R=false;
	if(X>='A'&&X<='C') ch_X=true;
	else ch_X=false;
	//cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<d<<"\n"<<R<<"\n"<<X<<"\n";
	//1
	cout<<(a==b) ? 1:0;
	//2
	cout<<((c==d)&&(a==b)) ? 1:0;
	//3
	cout<<((a==b)&&(c==d)&&(ch_R==ch_X)) ? 1:0;
	//4 
	cout<<((a==b)&&(c==d)&&check_4(R,X)&&(ch_R==ch_X)) ? 1:0;
	return 0;
}
