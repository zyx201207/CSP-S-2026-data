#include<bits/stdc++.h>
using namespace std;
int  so,co;
string st,ct;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>so>>st>>co>>ct;
	if(so==co)	a=1;
	else a=0;
	if(st[0]==ct[0] and st[1]==ct[1]){
		b=1;
		if((st[2]=='A' and ct[2]=='B') or (st[2]=='A' and ct[2]=='C') or (st[2]=='B' and ct[2]=='A') or (st[2]=='B' and ct[2]=='C') or (st[2]=='C' and ct[2]=='A') or (st[2]=='C' and ct[2]=='B') or (st[2]=='D' and ct[2]=='F') or (st[2]=='F' and ct[2]=='D')){
			c=1;
			if((st[2]=='A' and ct[2]=='B') or (st[2]=='B' and ct[2]=='C') or (st[2]=='D' and ct[2]=='F') or (st[2]=='F' and ct[2]=='D') or (st[2]=='C' and ct[2]=='B') or (st[2]=='B' and ct[2]=='A')){
				d=1;
				
			}
		}	
	}
	if(st[2]==ct[2]){
		b=0;
		c=0;
		d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}

