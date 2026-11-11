#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rc,xc,rp,xp;
char rz,xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	for(ll i=0;i<2;i++){
		rc=rc*10+s1[i]-'0';
		xc=xc*10+s3[i]-'0';
		rp=rp*10+s2[i]-'0';
		xp=xp*10+s4[i]-'0';
	}
	rz=s2[2],xz=s4[2];
	if(rz=='F') rz='E';
	if(xz=='F') xz='E';
	if(rc!=xc) cout<<"0000";
	else{
		if(rp!=xp) cout<<"1000";
		else{
			if((rz>='A'&&rz<='C'&&xz>='A'&&xz<='C')||(rz>='D'&&rz<='E'&&xz>='D'&&xz<='E')){
				if(abs(rz-xz)!=1||(rz=='C'&&xz=='D')||(rz=='D'&&xz=='C')) cout<<"1110";
				else cout<<"1111";
			}
			else cout<<"1100";
		} 
	}
	return 0;
}
