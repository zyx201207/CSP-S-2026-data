#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int lr,lx,rr,rx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		lr=(s1[0]-'0')*10+(s1[1]-'0');
		lx=(s2[0]-'0')*10+(s2[1]-'0');
		if(lr==lx){
			cout<<1;
			rr=s1[2]-'A';
			if(rr==5)rr--;
			rx=s2[2]-'A';
			if(rx==5)rx--;
			if(!((rr<3)^(rx<3))){
				cout<<1;
				if(abs(rr-rx)==1)cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
