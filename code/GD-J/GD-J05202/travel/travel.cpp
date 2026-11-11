#include <bits/stdc++.h>
using namespace std;
char a[50][50], x, y;
int cmp (int x, int y) {
	if (a[x][1]==a[y][1]&&a[x][2]==a[y][2]) return 1;
	else return 0;
}
int main (){
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	scanf ("%s%s%s%s", a[1]+1, a[2]+1, a[3]+1, a[4]+1);
	if (cmp (1, 3)) {
		printf ("1");
		if (cmp (2, 4)) {
			printf ("1");
			x=a[2][3], y=a[4][3];
			if ('A'<=x&&x<='C') {
				if (y>'C') printf ("00");
				else {
					printf ("1");
					if (y-x==1||x-y==1) printf ("1");
					else printf ("0");
				}
			}
			else {
				if (y>'C') {
					if (x-y==1||y-x==1) printf ("1");
					else printf ("0");
				}
				else printf ("00");
			}			
		}
		else printf ("000");		
	}
	else printf ("0000");
	return 0;
} 
