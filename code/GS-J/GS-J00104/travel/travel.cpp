#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) {

		if(s1[0]==s2[0]&&s1[1]==s2[1]) {

			if((('A'<=s1[2]&&s1[2]<='C')&&('A'<=s2[2]&&s2[2]<='C'))||(('D'<=s1[2]&&s1[2]<='E')&&('D'<=s2[2]&&s2[2]<='E'))) {

				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]) {
					printf("1111");
				} else {
					printf("1110");
				}
			} else {
				printf("1100");
			}
		} else {
			printf("1000");
		}
	} else {
		printf("0000");
	}
	return 0;
}
