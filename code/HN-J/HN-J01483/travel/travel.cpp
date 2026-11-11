#include<bits/stdc++.h>
#define int long long
using namespace std;
string ac,az,bc,bz,l,r;
char a,b;
bool fl,zz;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ac>>az>>bc>>bz;
	if(ac==bc){
		cout<<"1";
		zz=true;
	}
	else{
		cout<<"0";
		zz=false;
	} 
	if(zz==false){
		cout<<"000";
		return 0;
	}
	l=az[0]+az[1];
	r=bz[0]+bz[1];
	if(l==r){
		cout<<"1";
		fl=true;
	}
	else{
		cout<<"0";
		fl=false;
	}
	a=az[2];b=bz[2];
	if((a=='F' && b=='D' && fl) || (a=='D' && b=='F' && fl)){
		cout<<"1";
	}
	else if((a=='C' || a=='B' || a=='A') && (b=='A' || b=='B' || b=='C') && fl){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(fl==false || (a=='C' && b=='D') || (a=='D' && b=='C')){
		cout<<"0";
	}
	else if((a+1==b || a-1==b) && fl==true){
		cout<<"1";
	}
	else{
		cout<<"0";
	} 
	return 0;
}
