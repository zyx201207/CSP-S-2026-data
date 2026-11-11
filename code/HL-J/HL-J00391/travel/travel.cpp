#include<bits/stdc++.h>
using namespace std;
int rx,xx;
int a,b,c,d;
int rp,xp;
char rz,xz;
int mian(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d %d %d %d %d",rx,rp,rz,xx,xp,xz);
	if(rx==xx){
		a=1;
	}else if(rx!=xx){
		a=0;
	}
	if(rp==xp){
		b=1;
		if(rz=='D'){
			if(xz=='F'){
				c=1;
				d=1;
			}else if(xz!='F'){
				c=0;
				d=0;
			}
		}
		if(rz=='F'){
			if(xz=='D'){
				c=1;
				d=1;
			}else if(xz!='D'){
				c=0;
				d=0;
			}
		}
		if(rz=='A'){
			if(xz=='B'){
				c=1;
				d=1;
			}
			if(xz=='C'){
				c=1;
				d=0;
			}
		}
		if(rz=='B'){
			if(xz=='A'){
				c=1;
				d=1;
			}
			if(xz=='C'){
				c=1;
				d=1;
			}
		}
		if(rz=='C'){
			if(xz=='B'){
				c=1;
				d=1;
			}
			if(xz=='A'){
				c=1;
				d=0;
			}
		}
	}else if(rp!=xp){
		b=0;
		c=0;
		d=0;
	}
	printf("%d %d %d %d",a,b,c,d);
	return 0;
} 
