#include<bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		printf("0000\n");
		return 0;
	}
	printf("1");
	p1=s1[1]-'0';
	p2=s2[1]-'0';
	if(p1!=p2){
		printf("000\n");
		return 0;
	}
	printf("1");
	p1=s1[2]>='D'?2:1;
	p2=s2[2]>='D'?2:1;
	if(p1!=p2){
		printf("00\n");
		return 0;
	}
	printf("1");
	if(s1[2]+1==s2[2]&&s1[2]!='C'||s1[2]-1==s2[2]&&s1[2]!='D') printf("1\n");
	else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D') printf("1\n");
	else printf("0\n");
	return 0;
}
