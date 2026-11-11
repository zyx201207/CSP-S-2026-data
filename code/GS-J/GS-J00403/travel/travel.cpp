#include<bits/stdc++.h>
using namespace std;
struct zwh{
	string cx;
	string zw;
}r,x;
int r_[3],x_[3];
bool pd[2]={false};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r.cx>>r.zw>>x.cx>>x.zw;
	if(r.cx[0]=='0')r_[1]=r.cx[1]-'0';
	else r_[1]=r.cx[1]-'0'+10;
	if(x.cx[0]=='0')x_[1]=x.cx[1]-'0';
	else x_[1]=x.cx[1]-'0'+10;
	if(r.zw[0]=='0')r_[2]=r.zw[1]-'0';
	else r_[2]=r.zw[1]-'0'+10;
	if(x.zw[0]=='0')x_[2]=x.zw[1]-'0';
	else x_[2]=x.zw[1]-'0'+10;
	if(r_[1]!=x_[1]){
		cout<<0<<0<<0<<0;
		return 0;
	}
	cout<<1;
	if(r_[2]!=x_[2]){
		cout<<0<<0<<0;
		return 0;
	}
	cout<<1;
	if(r.zw[2]=='A'||r.zw[2]=='C')pd[0]=false;
	else pd[0]=true;
	if(x.zw[2]=='A'||x.zw[2]=='C')pd[1]=false;
	else pd[1]=true;
	if(pd[0]!=pd[1]){
		cout<<0<<0;
		return 0;
	}
	cout<<1;
	if(r.zw[2]-x.zw[2]==1||x.zw[2]-r.zw[2]==1)cout<<1;
	else cout<<0;
	return 0;
}
