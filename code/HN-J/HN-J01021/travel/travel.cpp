#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r1,x1,r2,x2;
	char r3,x3;
	cin>>r1>>r2>>r3>>x1>>x2>>x3;
	if(r1!=x1){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(r2!=x2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((r3>='D'&&x3<='C')||(r3<='C'&&x3>='D')){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(r3-x3!=1&&r3-x3!=-1){
		cout<<"0";
		return 0;
	}
	cout<<1;
	return 0;
} 
