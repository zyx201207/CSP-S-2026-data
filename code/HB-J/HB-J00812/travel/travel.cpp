#include<bits/stdc++.h>
using namespace std;
string n,nz;
string m,mz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>nz;
	cin>>m>>mz;
	int a,b;
	if(n[0]=='0'){
		a=int(n[1]);
	}
	else{
		a=int(n[0])+int(n[1]);
	}
	if(m[0]=='0'){
		b=int(m[1]);
	}
	else{
		b=int(m[0])+int(m[1]);
	}
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
	}
	int c,d;
	if(nz[0]=='0'){
		c=int(nz[1]);
	}
	else{
		c=int(nz[0])+int(nz[1]);
	}
	if(mz[0]=='0'){
		d=int(mz[1]);
	}
	else{
		d=int(mz[0])+int(mz[1]);
	}
	if(c!=d){
		cout<<"000";
		return 0;
	}
	else{
		cout<<1;
	}
	if((nz[2]=='D'&&mz[2]=='C')||(nz[2]=='C'&&mz[2]=='D')){
		cout<<"00";
		return 0;
	}
	else{
		cout<<1;
	}
	if((nz[2]=='A'&&mz[2]=='B')||(nz[2]=='B'&&mz[2]=='A')||(nz[2]=='B'&&mz[2]=='C')||(nz[2]=='C'&&mz[2]=='B')||(nz[2]=='F'&&mz[2]=='D')||(nz[2]=='D'&&mz[2]=='F')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
