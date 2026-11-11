#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;
char x, y;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c", &a, &b, &x, &c, &d, &y);
	if(a == c) {
		printf("1");
		if(b == d) {
			printf("1");
			if(('A' <= x && x <= 'C' && 'A' <= y && y <= 'C') || ('D' <= x && x <= 'E' && 'D' <= y && y <= 'E')) {
				printf("1");
				if(abs ( int(x - y) ) == 1) printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
