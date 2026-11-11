#include<bits/stdc++.h>
using namespace std;

string rz,xz;int rx,xx,rp,xp;bool rc,xc,a[5];
int transfering(string s){
	return (s[0]-48)*10+s[1]-48;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> rx >> rz >> xx >> xz;
	if(rx==xx)cout << '1';
	else{
		cout << "0000";
		return 0;
	}
	
	rp=transfering(rz);
	xp=transfering(xz);
	if(rp==xp)cout << '1';
	else{
		cout << "000";
		return 0;
	}
	
	if(rz[2]=='D'||rz[2]=='F')rc=1;
	if(xz[2]=='D'||xz[2]=='F')xc=1;
	if(rc==xc)cout << '1';
	else{
		cout << "00";
		return 0;
	}
	
	if(rc==1)cout << '1';
	else{
		if(rz[2]=='A')a[1]=1;
		if(rz[2]=='B')a[2]=1;
		if(rz[2]=='C')a[3]=1;
		if(xz[2]=='A')a[1]=1;
		if(xz[2]=='B')a[2]=1;
		if(xz[2]=='C')a[3]=1;
		if((a[1]&&a[2])||(a[2]&&a[3]))cout << '1';
		else cout << '0';
	}
	return 0;
} 
