#include<iostream>
#include<string>
using namespace std;
int num(string s){
	return 10*(s[0]^32)+(s[1]^32);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f1=c1==c2;
	bool f2=(f1&&num(s1)==num(s2));
	char g1=s1[2],g2=s2[2];
	bool f3=(f2&&((g1<='C'&&g2<='C')||(g1>='D'&&g2>='D')));
	bool f4=(f3&&abs(g1-g2)==1);
	cout<<f1<<f2<<f3<<f4; 
	return 0;
}
/*
02 01A 02 01B
1111
*/
/*
02 02B 02 01A
1000
*/
