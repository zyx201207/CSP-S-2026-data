#include<bits/stdc++.h>
using namespace std;
string rh,rw,xh,xw;
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rh>>rw>>xh>>xw;
	if(rh==xh)cout<<1;
	else cout<<0;
	if(rh==xh&&rw.substr(0,2)==xw.substr(0,2))cout<<1;
	else cout<<0;
	if(rh==xh&&rw.substr(0,2)==xw.substr(0,2)&&rw[2]>='A'&&rw[2]<='C'&&xw[2]>='A'&&xw[2]<='C')cout<<1;
	else if(rh==xh&&rw.substr(0,2)==xw.substr(0,2)&&rw[2]>='D'&&rw[2]<='F'&&xw[2]>='D'&&xw[2]<='F')cout<<1;
	else cout<<0;
	if(rh==xh&&rw.substr(0,2)==xw.substr(0,2)&&rw[2]>='A'&&rw[2]<='C'&&xw[2]>='A'&&xw[2]<='C'&&abs(rw[2]-xw[2])==1)cout<<1;
	else if(rh==xh&&rw.substr(0,2)==xw.substr(0,2)&&rw[2]>='D'&&rw[2]<='F'&&xw[2]>='D'&&xw[2]<='F'&&abs(rw[2]-xw[2])==1)cout<<1;
	else cout<<0;
}
