#include <bits/stdc++.h>
using namespace std;
string r,x,rz,xz,ans;
bool f=0,fl=0,flo=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rz>>x>>xz;
	string az,bz;
	char a,b;
	az+=rz[0];
	az+=rz[1];
	bz+=xz[0];
	bz+=xz[1];
	a=rz[2];
	b=xz[2]; 
	if(r==x)ans+='1',flo=1;
	else ans+='0';
	if(az==bz&&flo)ans+='1',f=1;
	else ans+='0',f=0;
	if(!f||!flo)ans+='0';
	else if(a>='D'&&a<='F'&&b>='D'&&b<='F')ans +='1',fl=1;
	else if(a>='A'&&a<='C'&&b>='A'&&b<='C')ans +='1',fl=1;
	else ans+='0';
	if(!fl||!f||!flo)ans+='0';
	else if(a+1==b||a-1==b) ans+='1';
	else ans+='0';
	cout <<ans;
	return 0;
} 
