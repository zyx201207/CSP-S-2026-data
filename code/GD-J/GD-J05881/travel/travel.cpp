#include <cstdio>
#include <cstring>
#define ll long long
const int N = 2e5 + 5;
using namespace std;

char c1[10],s1[10],c2[10],s2[10];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s",c1);
	scanf("%s",s1);
	scanf("%s",c2);
	scanf("%s",s2);
	if(strcmp(c1,c2)) puts("0000");
	else{
		putchar('1');
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			putchar('1');
			int f1 = s1[2] <= 'C';
			int f2 = s2[2] <= 'C';
			if(f1 ^ f2) puts("00");
			else{
				putchar('1');
				if(s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1) putchar('1');
				else putchar('0');
			}
		}
		else puts("000");
	}
	return 0;
}

