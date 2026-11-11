#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int Ra,Xa,Rb,Xb,Rt,Xt;
	string Rs,Xs;
	cin>>Ra>>Rs>>Xa>>Xs;
	Rb=Rs[2]-'A';
	Xb=Xs[2]-'A';
	if(Rb==0 || Rb==1 || Rb==2){
		Rt=1;
	}else{
		Rt=2;
	}
	if(Xb==0 || Xb==1 || Xb==2){
		Xt=1;
	}else{
		Xt=2;
	}
	if(Ra==Xa){
		cout<<1;
	}else{
		cout<<0;
	}
	if(Ra==Xa && Rs.substr(0,2)==Xs.substr(0,2)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(Ra==Xa && Rs.substr(0,2)==Xs.substr(0,2) && Rt==Xt){
		cout<<1;
	}else{
		cout<<0;
	}
	if(Ra==Xa && Rs.substr(0,2)==Xs.substr(0,2) && Rt==Xt && abs(Rb-Xb)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
