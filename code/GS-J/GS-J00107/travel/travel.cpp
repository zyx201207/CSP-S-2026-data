#include<bits/stdc++.h>
using namespace std;
string Sr_che,sr_seat,Sx_che,sx_seat;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>Sr_che>>sr_seat>>Sx_che>>sx_seat;
	if(Sr_che==Sx_che) {
		printf("1");
	} else {
		printf("0000");
		return 0;
	}
	
	bool flag=0;
	for(int i=0; i<2; ++i) {
		if(sr_seat[i]!=sx_seat[i]) {
			printf("000");
			return 0;
		} else flag=1;
	}
	if(flag) printf("1");
	
	if(sr_seat[2]=='A'||sr_seat[2]=='B'||sr_seat[2]=='C') {
		if(sx_seat[2]=='A'||sx_seat[2]=='B'||sx_seat[2]=='C') {
			printf("1");
		} else {
			printf("00");
			return 0;
		}
	} 
	else if(sr_seat[2]=='D'||sr_seat[2]=='F') {
		if(sx_seat[2]=='D'||sx_seat[2]=='F') {
			printf("1");
		} else {
			printf("00");
			return 0;
		}
	}
	
	if(sr_seat[2]=='A') {
		if(sx_seat[2]=='B') {
			printf("1");
		} 
		else printf("0");
	} 
	else if(sr_seat[2]=='B') {
		if(sx_seat[2]=='A'||sx_seat[2]=='C') {
			printf("1");
		} 
		else printf("0");
	} 
	else if(sr_seat[2]=='C') {
		if(sx_seat[2]=='B') {
			printf("1");
		} 
		else printf("0");
	} 
	else if(sr_seat[2]=='D') {
		if(sx_seat[2]=='F') {
			printf("1");
		} 
		else printf("0");
	} 
	else if(sr_seat[2]=='F') {
		if(sx_seat[2]=='D') {
			printf("1");
		} 
		else printf("0");
	}
	return 0;
}
