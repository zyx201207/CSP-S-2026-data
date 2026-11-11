#include<bits/stdc++.h>

int a1, b1; char a2[4], b2[4];

int main(){
	freopen("travel.in", "r", stdin); freopen("travel.out", "w", stdout);
	scanf("%d%s%d%s", &a1, a2 + 1, &b1, b2 + 1);
	if(a2[3] > b2[3]) std::swap(a2, b2);
	if(a1 == b1){
		putchar('1');
		if(a2[1] == b2[1] && a2[2] == b2[2]){
			putchar('1');
			if((a2[3] == 'A' && b2[3] == 'B') || (a2[3] == 'A' && b2[3] == 'C') || (a2[3] == 'B' && b2[3] == 'C') ||
			(a2[3] == 'D' && b2[3] == 'F')){
				putchar('1');
				if((a2[3] == 'A' && b2[3] == 'B') || (a2[3] == 'B' && b2[3] == 'C') || (a2[3] == 'D' && b2[3] == 'F')){
					puts("1");
				}else puts("0");
			}else puts("00");
		}else puts("000");
	}else puts("0000");
}
