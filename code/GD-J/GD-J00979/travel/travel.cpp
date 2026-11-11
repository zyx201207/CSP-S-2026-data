#include<bits/stdc++.h>
using namespace std;
string sr,ssr,sx,ssx;
long long rf=0,xf=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sr>>ssr>>sx>>ssx;
	if (sr==sx){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	
	
	if (ssr[0]+ssr[1]==ssx[0]+ssx[1]){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	
	
	if (ssr[2]=='A' || ssr[2]=='B' || ssr[2]=='C'){
		rf=1;
	}
	if (ssx[2]=='A' || ssx[2]=='B' || ssx[2]=='C'){
		xf=1;
	}
	if (ssr[2]=='D' || ssr[2]=='E'){
		rf=2;
	}
	if (ssr[2]=='D' || ssr[2]=='E'){
		rf=2;
	}
	if (rf==1 && xf==1 || rf==2 && xf==2){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	
	
	if (rf!=xf || rf==0 && xf==0){
		cout<<'0';
	}else if (rf==2 && xf==2){
		cout<<'1';
	}else{
		if (abs(ssr[2]-ssx[2])==1){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}
	return 0;
} 
