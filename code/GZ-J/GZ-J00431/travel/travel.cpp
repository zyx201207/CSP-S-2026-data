//GZ-J00431 贵阳一中李端棻中学 田贺铭 
#include<bits/stdc++.h>
using namespace std;
long long cr,cx,srp,sxp,n;
char sr,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>srp>>sr>>cx>>sxp>>sx;
	if(cr==cx)cout<<1;
	if(cr!=cx){
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(srp==sxp)cout<<1;
	if(srp!=sxp){
		cout<<0<<0<<0;
		return 0;
	}
	if(sr=='D'&&sx=='C'||sr=='C'&&sx=='D'){
		cout<<0<<0;
		n=1;
		return 0;
	}
	if(n==0)cout<<1;
	if(char(sr+1)==sx||char(sx+1)==sr){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
} 
