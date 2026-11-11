#include<bits/stdc++.h>
using namespace std;
int rx,ry,xx,xy;
string rs,xs;
bool c1(){
	int r = rs[0]-'A';
	int x = xs[0]-'A';
	if(r<=2&&x<=2) return true;
	if(r>=3&&x>=3) return true;
	return false;
}
bool c2(){
	int r = rs[0]-'A';
	int x = xs[0]-'A';
	if(r-x==1||x-r==1){
		if(r==2&&x==3) return false;
		if(r==3&&x==2) return false;
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rx>>ry>>rs>>xx>>xy>>xs;
	if(rx!=xx){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(ry!=xy){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(!c1()){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(!c2()){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}
