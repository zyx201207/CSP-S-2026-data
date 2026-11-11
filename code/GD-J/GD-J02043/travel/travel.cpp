#include <bits/stdc++.h>
using namespace std;
string rcar,rchair,xcar,xchair;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rcar>>rchair>>xcar>>xchair;
	if(rcar==xcar){
		cout<<1;
	}else{
		cout<<0;
	}
	if(rcar==xcar&&rchair[0]==xchair[0]&&rchair[1]==xchair[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	bool same_side=false;
	if((rchair[2]>='D'&&xchair[2]>='D')||(rchair[2]<='D'&&xchair[2]<='D')){
		same_side=true;
	}else{
		cout<<0;
	}
	if(rcar==xcar&&rchair[0]==xchair[0]&&rchair[1]==xchair[1]&&same_side){
		cout<<1;
	}else{
		cout<<0;
	}
	bool beside=false;
	if(abs(rchair[2]-xchair[2])==1){
		beside=true;
	}
	if(rcar==xcar&&rchair[0]==xchair[0]&&rchair[1]==xchair[1]&&same_side&&beside){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
