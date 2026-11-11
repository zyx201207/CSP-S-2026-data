#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool a,b,c,d;
bool isSameSide(string s1,string s2){
	char t1=s1[2];
	char t2=s2[2];
	if(
	(t1=='A'&&(t2=='B'||t2=='C'))||
	(t1=='B'&&(t2=='A'||t2=='C'))||
	(t1=='C'&&(t2=='B'||t2=='A')))return 1;
	if((t1=='D'&&t2=='F')||(t1=='F'&&t2=='D'))return 1;
	return 0;
}
bool isNear(string s1,string s2){
	char t1=s1[2];
	char t2=s2[2];
	if(t1=='A'&&t2=='B')return 1;
	if(t1=='B'&&(t2=='A'||t2=='C'))return 1;
	if(t1=='C'&&t2=='B')return 1;
	if(t1=='D'&&t2=='F')return 1;
	if(t1=='F'&&t2=='D')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(c1==c2);
	b=(s1[0]==s2[0])&&(s1[1]==s2[1])&&a;
	c=isSameSide(s1,s2)&&b;
	d=isNear(s1,s2)&&c;
	cout<<a?1:0;
	cout<<b?1:0;
	cout<<c?1:0;
	cout<<d?1:0;
	return 0;
}

