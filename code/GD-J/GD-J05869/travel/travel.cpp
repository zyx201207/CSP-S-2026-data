#include<bits/stdc++.h>
#include<string>
using namespace std;
int carr,carx;
string seatr,seatx;
string r,x;
char albr,albx;
char a[2]={'D','F'},o,p;
bool i,v;
int rr,xx,rrr,xxx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>carr>>seatr>>carx>>seatx;
	if(carr==carx){
		cout<<1;
	}
	else cout<<0;
	r=seatr[0]+seatr[1];
	x=seatx[0]+seatx[1];
	if(carr==carx&&r==x){
		cout<<1;
		i=true;
	}
	else cout<<0;
	albr=seatr[2];
	albx=seatx[2];
	o=albr;
	p=albx;
	for(int i=0;i<2;i++){
		if(o==a[i]){
			rr=1;
		}
		else rr=2;
	}
	for(int j=0;j<2;j++){
		if(p==a[i]){
			xx=1;
		}
		else xx=2;
	}
	if(i==true&&rr==xx){
		cout<<1;
		v=true;
	}
	else cout<<0;
	rrr=o;
	xxx=p;
	if(v==true&&(rrr-xxx==1||rrr-xxx==-1)){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
