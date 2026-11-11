#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	// 10 10 A 20 20 B
	int rc,rp,xc,xp;
	char rz, xz;
	scanf("%d %d %c %d %d %c", &rc,&rp,&rz,&xc,&xp,&xz);
	int r = 'A' <= rz <= 'C';
	int x = 'A' <= xz <= 'C';
	printf("%d%d%d%d\n", rc==xc, rc==xc&&rp==xp,rc==xc&&rp==xp&&(!(r^x)),rc==xc&&rp==xp&&(!(r^x))&&abs(rz-xz)==1);
	return 0;
} 
