#include<bits/stdc++.h>
using namespace std;
string c[2], s[2];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c[0] >> s[0] >> c[1] >> s[1];
	if(c[0] == c[1]){
		if(s[0][0] == s[1][0] && s[0][1] == s[1][1]){
			if((s[0][2] == 'D' && s[1][2] == 'F') || (s[0][2] == 'F' && s[1][2] == 'D')){
				printf("1111\n");
			}else if((s[0][2] == 'A' || s[0][2] == 'B' || s[0][2] == 'C') && (s[1][2] == 'A' || s[1][2] == 'B' || s[1][2] == 'C')){
				if(abs(s[0][2] - s[1][2]) == 1){
					printf("1111\n");
				}else{
					printf("1110\n");
				}
			}else{
				printf("1100\n");
			}
		}else{
			printf("1000\n");
		}
	}else{
		printf("0000\n");
	}
	return 0;
}
