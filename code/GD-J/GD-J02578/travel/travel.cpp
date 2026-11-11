#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	//两张车票对应的座位是否在同一节车厢-
	if(s1==s3) {
		printf("1");
	} else {
		printf("0000");
		return 0;
	}
	//两张车票对应的座位是否在同一节车厢的同一排-
	if(s2[0]==s4[0] && s2[1]==s4[1]) {
		printf("1");
	} else {
		printf("000");
		return 0;
	}
	// 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧-
	if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C') {
		if(s4[2]=='A' || s4[2]=='B' || s4[2]=='C') {
			printf("1");
			//两张车票对应的座位是否相邻-
			if(s2[2]=='A' && s4[2]=='B' || s2[2]=='b' && s4[2]=='c') {
				printf("1");
			} else {
				printf("0");
			}
		} else {
			printf("00");
		}
	} else {
		if(s4[2]=='D' || s4[2]=='F') {
			printf("11");
		} else {
			printf("00");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
