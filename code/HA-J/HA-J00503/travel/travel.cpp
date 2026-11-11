#include<bits/stdc++.h>
using namespace std;

struct tra{
	string n;
	string m;
};
tra a;
tra b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.n>>a.m>>b.n>>b.m;
	int ac=0;
	for(int i=0;i<a.n.size();i++){
		if(a.n[i]==b.n[i]){
			ac++;
		}
	}
	if(ac==a.n.size()){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	ac=0;
	for(int j=0;j<2;j++){
		if(a.m[j]==b.m[j]){
			ac++;
		}
	}
	if(ac==2){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	
	if(a.m[2]<='C'&&b.m[2]<='C'){
		cout<<"1";
	}
	else if(a.m[2]>='D'&&b.m[2]>='D'){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if((a.m[2]=='A'||a.m[2]=='B')&&(b.m[2]=='B'||b.m[2]=='A')){
		cout<<"1";
	}
	else if((a.m[2]=='C'||a.m[2]=='B')&&(b.m[2]=='B'||b.m[2]=='C')){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
