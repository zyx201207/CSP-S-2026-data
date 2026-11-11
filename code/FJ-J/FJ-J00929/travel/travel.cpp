#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int f=0,t=0;
int main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<1;
	else cout<<0;
	if(a2[0]==b2[0]&&a2[1]==b2[1]) {
		cout<<1;
		f=1;
	}
	else cout<<0;
	if(f==1&&a2[2]<=67&&b2[2]<=67){
		cout<<1;
		t=1;
	}else if(f==1&&a2[2]>67&&a2[2]<=69&&b2[2]>67&&b2[2]<=70){
		cout<<1;
		t=1;
	}
	else cout<<0;
	if(t!=1){
		cout<<0;
		return 0;
	}
	else if(a2[2]=='D'&&b2[2]=='F'){
		cout<<1;
		return 0;
	}else if(a2[2]=='F'&&b2[2]=='D'){
		cout<<1;
		return 0;
	}
	t=abs(a2[2]-b2[2]);
	if(t==1) cout<<1;
	else cout<<0;

	return 0;
}
