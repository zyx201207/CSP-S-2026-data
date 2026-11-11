#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool line(string x,string y){
	char n=x[2],m=y[2];
	return ((n=='A'||n=='B'||n=='C')&&(m=='A'||m=='B'||m=='C'))||((n=='D'||n=='F')&&(m=='D'||m=='F'));
}
int stoint(string s){
	int h=0,f=1;
	for(int i=s.size()-1;i>=0;i--){
		h+=int(s[i]-'0')*f;
		f*=10;
	}
	return h;
}
bool guo(char x,char y){
	return ((x=='A'||x=='B'||x=='C')&&(y=='D'||y=='F'))||((y=='A'||y=='B'||y=='C')&&(x=='D'||x=='F'));
}
bool nei(){
	string x=b.substr(0,2),y=d.substr(0,2);
	if(a!=c||b[2]-d[2]>1||stoint(x)-stoint(y)>1||guo(b[2],d[2])||(b[2]-d[2]==1&&stoint(x)-stoint(y)==1)) return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	cout<<(a==c)<<(a==c&&b[0]==d[0]&&b[1]==d[1])<<(a==c&&b[0]==d[0]&&b[1]==d[1]&&line(b,d))<<nei();
	return 0;//誓死效忠绝区0!!! 挽昼大人万岁!!! 
}
