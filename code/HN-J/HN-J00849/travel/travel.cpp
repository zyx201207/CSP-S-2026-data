#include<bits/stdc++.h>
using namespace std;
string ca,cb,sa,sb;
int ag,bg;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca == cb){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(sa[0] == sb[0] && sa[1] == sb[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	for(int i = 0;i < 5;i++){
		if(sa[2] == 'A' + i){
			ag = i;
		}
		if(sb[2] == 'A' + i){
			bg = i;
		}
	}
	if((ag <= 2 && bg <= 2) || (ag > 2 && bg > 2)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(ag - bg) == 1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
