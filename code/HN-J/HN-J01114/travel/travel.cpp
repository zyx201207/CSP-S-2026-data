#include <bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2,r,x;
int ro,rt,xo,xt;
string z[]={"A","B","C"};
string y[]={"D","F"};
int f(string a,string b){
	bool flag1=false,flag2=false;
	for(int i=0;i<3;i++){
		if(a==z[i]) flag1=true;
		if(b==z[i]) flag2=true;
	}
	if(flag1==flag2) return true;
	return false;
}
int zw(string a,string b){
	for(int i=1;i<3;i++){
		if((z[i-1]==a&&z[i]==b)||(z[i-1]==b&&z[i]==a)) return true;
	}
	if((y[0]==a&&y[1]==b)||(y[0]==b&&y[1]==a)) return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1[0]=='0') ro=r1[1]-'0';
	else ro=r1[0]-'0'*10+(r1[1]-'0');
	if(r2[0]=='0') rt=r2[1]-'0';
	else rt=r2[0]-'0'*10+(r2[1]-'0');
	if(x1[0]=='0') xo=x1[1]-'0';
	else xo=x1[0]-'0'*10+(x1[1]-'0');
	if(x2[0]=='0') xt=x2[1]-'0';
	else xt=x2[0]-'0'*10+(x2[1]-'0');
	r=r2[2],x=x2[2];
	if(ro==xo) cout<<1;
	else cout<<0;
	if(ro==xo&&rt==xt) cout<<1;
	else cout<<0;
	if(ro==xo&&rt==xt&&f(r,x)) cout<<1;
	else cout<<0;
	if(ro==xo&&rt==xt&&f(r,x)&&zw(r,x)) cout<<1;
	else cout<<0;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
