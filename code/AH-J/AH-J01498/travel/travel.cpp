#include<bits/stdc++.h>
using namespace std;
int c1, c2, p1, p2;
char z1, z2;
string s1, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1;
	getchar();
	cin >> s1 >> c2;
	getchar();
	cin >> s2;
	if (c1 == c2) {
		printf("1");
		for(int i = 0; i <= 2; ++i){
			if(i < 2){
				p1 *= 10;
				p1 += s1[i];
				p2 *= 10;
				p2 += s2[i];
			} else {
				z1 = s1[i];
				z2 = s2[i];
			}
		}
		if (p1 == p2) {
			printf("1");
			if (('A' <= z1 && z1 <= 'C') && ('A' <= z2 && z2 <= 'C')) {
				printf("1");
				if (z1 > z2 && z1 - 1 == z2) {
					printf("1");
				} else if (z2 - 1 == z1) {
					printf("1");
				} else {
					printf("0");
				}
			} else if (('D' == z1 && z2 == 'F') || ('F' == z1 && z2 == 'D')) {
				printf("11");
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
