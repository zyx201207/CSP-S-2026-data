#include<bits/stdc++.h>
using namespace std;
string s1,r1,s2,r2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>r1>>s2>>r2;
	if(s1==s2) printf("1");
	else printf("0");
	//1
	if(s1==s2&&r1[0]==r2[0]&&r1[1]==r2[1]) printf("1");
	else printf("0");
	//2
	if(s1==s2&&r1[0]==r2[0]&&r1[1]==r2[1]){//先判断同一车厢，行
		if(r1[2]=='A'){
			if(r2[2]=='B') printf("11");
			else if(r2[2]=='C') printf("10");
			else printf("00");
		}
		if(r1[2]=='B'){
			if(r2[2]=='A'||r2[2]=='C') printf("11");
			else printf("00");
		}
		if(r1[2]=='C'){
			if(r2[2]=='B') printf("11");
			else if(r2[2]=='A') printf("10");
			else printf("00");
		}
		if(r1[2]=='D'){
			if(r2[2]=='F') printf("11");
			else printf("00");
		}
		if(r1[2]=='F'){
			if(r2[2]=='D') printf("11");
			else printf("00");
		}//每个if
	}
	else printf("00");//3 4
return 0;}