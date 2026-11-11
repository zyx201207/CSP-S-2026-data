#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rc,xc,rzp,xzp,pd=0;
	string rz,xz;
	cin>>rc>>rz>>xc>>xz;
	char r=rz[2],x=xz[2];
	if(rz[0]=='0'){
		rzp=rz[1];
	}
	else if(rz[0]=='1'){
		rzp=10+rz[1];
	}
	if(xz[0]=='0'){
		xzp=xz[1];
	}
	else if(xz[0]=='1'){
		xzp=10+xz[1];
	}
	if(rc==xc){
		cout<<1;
	}
	else cout<<0;
	if(rc==xc && rzp==xzp){
		cout<<1;
	}
	else cout<<0;
	if(rc==xc && rzp==xzp && rz[2]<='C' && xz[2]<='C' || rz[2]>'C' && xz[2]>'C'){
		cout<<1;
		pd=1;
	} 
	else{
		pd=0;
		cout<<0;
	}
	if(pd==0){
		cout<<0;
		return 0;
	}
	if(rc==xc && rzp==xzp && ((int)(r))+1==(int)(x) || (int)(x)+1==(int)(r) && pd){
		cout<<1;
	}
	return 0;
}
