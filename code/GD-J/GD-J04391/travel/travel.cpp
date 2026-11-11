#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string xb,xc,rb,rc;
	cin>>xb>>xc>>rb>>rc;
	int f=0,g=0,k=0;
	if(xb==rb){
		cout<<1;
		f=1;
	}	
	if(f==0){
		cout<<"0000";
		return 0;
	}
	
	
	if(xc[0]==rc[0] && xc[1]==rc[1]){
		cout<<1;
		g=1;
	}else cout<<0;
	
	
	if(((xc[2]>='A' && xc[2]<='C' && rc[2]>='A' && rc[2]<='C') || (xc[2]=='D' && rc[2]=='F') || (xc[2]=='F' && rc[2]=='D')) && g==1){
		cout<<1;
		k=1;
	}else cout<<0;
	
	if((xc[2]=='A' && rc[2]=='C') || (xc[2]=='C' && rc[2]=='A') || k!=1){
		cout<<0;
	}else if(k==1) cout<<1;
	
	
	return 0;
} 
