#include<bits/stdc++.h>
using namespace std;
char  a,b,c,d,a1,b1,c1,d1,b2,d2;
int z,x,cc,v,k1,k2;
int q,w,e,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1>>b2>>c>>c1>>d>>d1>>d2;
	 if(a=='0') z=a1-'0';
	 else z=(a-'0')*10+a1-'0';
	 if(c=='0') x=c1-'0';
	 else x=(c-'0')*10+c1-'0';
	 if(z==x) {
	//1Œ 
	     cc=(b-'0')*10+b1-'0';
	     v=(d-'0')*10+d1-'0';
	     if(cc==v) {
	     	//2Œ 
	     	if(b2<='C') k1=1;
	     	else k1=0;
	     	if(d2<='C'){
	     	 k2=1;	
			 }
	     	else k2=0;
	     	if(k1==k2){
	     		if(b2+1==d2||d2+1==b2) cout<<1111,exit(0);
	     		else cout<<1110,exit(0);
			 }
			 else cout<<1100,exit(0);
		 }
	     else{
	     	cout<<1000,exit(0);
		 }
	     
	 }
	 else cout<<"0000",exit(0); 
	  return 0;
	 
}

