#include <bits/stdc++.h>
using namespace std;
char c[5],s[5],C[5],S[5];
int main(void) {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c,s,C,S);
	if(c[0]==C[0]&&c[1]==C[1]) {
		if(s[0]==S[0]&&s[1]==S[1]) {
			if((s[2]<'D'&&S[2]<'D')||(s[2]>='D'&&S[2]>='D')) {
				if(s[2]==S[2]+1||S[2]==s[2]+1) printf("1111");
				else printf("1110");
			} else printf("1100");
		} else printf("1000");
	} else printf("0000");
	return 0;
}
