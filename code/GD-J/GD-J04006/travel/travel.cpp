#include <bits/stdc++.h>
using namespace std;
string n,m,x,y,t,p;
char r,d;
int main(){
	cin>>n>>m>>x>>y;
	if(n==x){
		cout<<'1';
	}else{
		cout<<'0000';
		return 0;
	}
	for(int i=0;i<=1;i++){
		t+=m[i];
		p+=y[i];
	}
	if(t==p){
		cout<<'1';
	}else{
		cout<<'000';
		return 0;
	}
	for(int i=2;i<=2;i++){
		r=m[i];
		d=y[i];
	}
	if((r>='A' && r<='C'&& d>='A' && d<='C')|| (r>='D' && r<='F'&& d>='D' && d<='F')){
		cout<<'1';
		if(char(r+1)==d || char(r-1)==d){
			cout<<'1';
		}else{
			cout<<'0';
			return 0;
		}
	}else{
		cout<<'00';
		return 0;
	}
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	return 0;
}
