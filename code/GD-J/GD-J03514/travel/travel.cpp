#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;
char a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	if(cx[0]==cy[0]&&cx[1]==cy[1]){
		a='1';
		if(sx[0]==sy[0]&&sx[1]==sy[1]){
			b='1';
			if(((sx[2]>='A'&&sx[2]<='C')&&(sy[2]>='A'&&sy[2]<='C'))||((sx[2]>='D'&&sx[2]<='E')&&(sy[2]>='D'&&sy[2]<='E'))){
				c='1';
				if(abs(sx[2]-sy[2])==1&&!(sx[2]=='C'&&sy[2]=='D')&&!(sx[2]=='D'&&sy[2]=='C')){
					d='1';
				}
				else{
					d='0';
				}
			}
			else{
				c='0';
				d='0';
			}
		}
		else{
			b='0';
			c='0';
			d='0';
		}
	}
	else{
		a='0';
		b='0';
		c='0';
		d='0';
	}
	cout<<a<<b<<c<<d;
	//ºÃÄÑ£¬£¡£¿ 8:49 T1 
	return 0;
}
