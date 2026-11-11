#include<bits/stdc++.h>
using namespace std;
int r,x;
string rs,xs;
bool ck(char a,char b){
	if(a<b){
		swap(a,b);
	}
	if(a-b!=1){
		return 0;
	}
	if(a=='D'){
		return 0;
	}
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rs>>x>>xs;
	char rc=rs[2],xc=xs[2];
	if(r!=x){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(rs[0]==xs[0]&&rs[1]==xs[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((rc<='C'&&xc<='C')||(rc>='D'&&rc<='F'&&xc>='D'&&xc<='F')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(ck(rc,xc)){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
