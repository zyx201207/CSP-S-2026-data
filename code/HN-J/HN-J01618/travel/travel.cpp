#include <bits/stdc++.h>
using namespace std;

char c1[4], s1[4], c2[4], s2[4];

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
	if(c1[2] != c2[2]){
		printf("0000");
	}else{
		if(s1[2] != s2[2]){
			printf("1000");
		}else{
			if(s1[3] < 'D' && s2[3] >= 'D' || s1[3] >= 'D' && s2[3] < 'D'){
				printf("1100");
			}else{
				if(s1[3] - s2[3] != 1 && s1[3] - s2[3] != -1){
					printf("1110");
				}else{
					printf("1111");
				}
			}
		}
	}
	return 0;
} 
