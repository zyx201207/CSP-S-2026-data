#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ca,cb;
	string sa,sb;
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb) printf("1");
	if(ca!=cb) printf("0");
	int sca=(sa[0]-'0')*10+(sa[1]-'0'),scb=(sb[0]-'0')*10+(sb[1]-'0');
	char ssa=sa[2],ssb=sb[2];
	if(sca==scb) printf("1");
	if(sca!=scb) printf("0");
	if((ssa=='A'||ssa=='B'||ssa=='C')&&(ssb=='A'||ssb=='B'||ssb=='C')){
		printf("1");
		if(ssa=='B'||ssb=='B'){
			printf("1");
		}else{
			printf("0");
		}
	}else if((ssa=='F'||ssa=='D')&&(ssb=='F'||ssb=='D')){
		printf("11");
	}else{
		printf("00");
	}
	return 0;
} 
