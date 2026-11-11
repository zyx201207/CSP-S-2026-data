#include<bits/stdc++.h>
using namespace std;
bool check1(char a,char b){
	if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')) return true;
	if((a=='E'||a=='F')&&(b=='E'||b=='F')) return true;
	return false;
}
bool check2(char a,char b){
	if(a>=b) swap(a,b);
	if(a=='A'&&b=='B') return true;
	if(a=='B'&&b=='C') return true;
	if(a=='D'&&b=='F') return true;
	return false;
}
char c(bool f){
	return (f?'1':'0');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char st1=s1[2],st2=s2[2];
	int b1=(s1[0]-'0')*10+(s1[1]-'0');
	int b2=(s2[0]-'0')*10+(s2[1]-'0');
	bool f1=(c1==c2);
	bool f2=f1&&(b1==b2);
	bool f3=f2&&check1(st1,st2);
	bool f4=f3&&check2(st1,st2);
	cout<<c(f1)<<c(f2)<<c(f3)<<c(f4);	
	
	return 0;
} 
