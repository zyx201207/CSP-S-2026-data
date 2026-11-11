#include<bits/stdc++.h>
using namespace std;
char q1[2],q2[3],w1[2],w2[3];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q1>>q2>>w1>>w2;
	if(q1[0]==w1[0]&&q1[1]==w1[1]) {
		printf("1");
		if(q2[0]==w2[0]&&q2[1]==w2[1]) {
			printf("1");
			if((q2[2]>=65&&q2[2]<=67)&&(w2[2]>=65&&w2[2]<=67)) {
				printf("1");
				if((q2[2]+1==w2[2])||(q2[2]-1==w2[2])){
					printf("1");
				}else {
					printf("0");
				}
			}else if((q2[2]>=68&&q2[2]<=69)&&(w2[2]>=68&&w2[2]<=69)) {
				printf("1");
				if((q2[2]+1==w2[2])||(q2[2]-1==w2[2])){
					printf("1");
				}else {
					printf("0");
				}
			} else {
				printf("00");
				}
		} else {
				printf("000");
			}
	} else {
		printf("0000");
	}
	
		return 0;
	}
