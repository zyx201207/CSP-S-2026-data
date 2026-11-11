#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int c1,c2,p1,p2;
char ch1,ch2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	c1 = (s1[0]-'0')*10+(s1[1]-'0');
	c2 = (s3[0]-'0')*10+(s3[1]-'0');
	p1 = (s2[0]-'0')*10+(s2[1]-'0');
	p2 = (s4[0]-'0')*10+(s4[1]-'0');
	ch1 = s2[2];
	ch2 = s4[2];
	if(c1!=c2){
		printf("0000");
		return 0;
	} 
	else printf("1");
	if(p1!=p2){
		printf("000");
		return 0;
	} 
	else printf("1");
	if(!((ch1<='C' && ch2<='C') || (ch1>='D' && ch2>='D'))){
		printf("00");
		return 0;
	} 
	else printf("1");
	if(abs(int(ch1-ch2))!=1){
		printf("0");
		return 0;
	} 
	else printf("1");
	return 0;
}
