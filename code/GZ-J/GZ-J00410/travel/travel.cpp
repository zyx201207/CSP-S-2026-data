//GZ-J00410 肖耿毅 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
string a2, b2;
int a1, b1;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1 == b1) {
		printf("1");
		if(a2[0] == b2[0] && a2[1] == b2[1]) {
			printf("1");
			if(a2[2] == 'A' && b2[2] == 'B') printf("11");
			else if(a2[2] == 'A' && b2[2] == 'C') printf("10");
			else if(a2[2] == 'A' && b2[2] == 'D') printf("00");
			else if(a2[2] == 'A' && b2[2] == 'F') printf("00");
			else if(a2[2] == 'B' && b2[2] == 'A') printf("11");
			else if(a2[2] == 'B' && b2[2] == 'C') printf("11");
			else if(a2[2] == 'B' && b2[2] == 'D') printf("00");
			else if(a2[2] == 'B' && b2[2] == 'F') printf("00");
			else if(a2[2] == 'C' && b2[2] == 'A') printf("10");
			else if(a2[2] == 'C' && b2[2] == 'B') printf("11");
			else if(a2[2] == 'C' && b2[2] == 'D') printf("00");
			else if(a2[2] == 'C' && b2[2] == 'F') printf("00");
			else if(a2[2] == 'D' && b2[2] == 'A') printf("00");
			else if(a2[2] == 'D' && b2[2] == 'B') printf("00");
			else if(a2[2] == 'D' && b2[2] == 'C') printf("00");
			else if(a2[2] == 'D' && b2[2] == 'F') printf("11");
			else if(a2[2] == 'F' && b2[2] == 'A') printf("00");
			else if(a2[2] == 'F' && b2[2] == 'B') printf("00");
			else if(a2[2] == 'F' && b2[2] == 'C') printf("00");
			else if(a2[2] == 'F' && b2[2] == 'D') printf("11");
		} else printf("000");
	} else printf("0000");
	puts("");
	return 0;
}
