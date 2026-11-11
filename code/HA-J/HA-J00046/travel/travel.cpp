#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
char r,x;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&c1,&s1,&r,&c2,&s2,&x);
	if(c1!=c2) {
		printf("0000");
		return 0;
	} else {
		printf("1");
		if(s1!=s2) {
			printf("000");
			return 0;
		} else {
			printf("1");
			if((r<='C'&&x>='D')||(x<='C'&&r>='D')) {
				printf("00");
				return 0;
			} else {
				printf("1");
				if(abs(r-x)==1||(r=='D'&&x=='F')||(r=='F'&&x=='D')) {
					printf("1");
					return 0;
				} else {
					printf("0");
					return 0;
				}
			}
		}
	}
	return 0;
}

