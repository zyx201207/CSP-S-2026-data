#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rcar,rseat,xcar,xseat;
	cin>>rcar>>rseat>>xcar>>xseat;
	if(rcar==xcar){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(rcar==xcar and rseat[1]==rseat[1]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(rcar==xcar and rseat[1]==rseat[1] and ((rseat[2]<='C' and xseat[2]<='C') or (rseat[2]>='D' and xseat[2]>='D'))){
		cout<<'1';
		bool flag=0;
		char tempr=rseat[2];
		char tempx=xseat[2];
		if(tempr+1==tempx){
			cout<<'1';
			flag=1;
		}
		if(tempr-1==tempx){
			cout<<'1';
			flag=1;
		}
		if(!flag){
			cout<<'0';
		}
	}else{
		cout<<'0';
		cout<<'0';
	}
	return 0;
}
