#include<bits/stdc++.h>
using namespace std;
int a,b;
string r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>r>>b>>x;
	if(a==b){
		cout<<1;
	}
	else if(a!=b){
		cout<<0<<0<<0<<0;
		return 0;
	}
	string r1;
	r1+=r[0];
	r1+=r[1];
	int num=stod(r1);
	
	string x1;
	x1+=x[0];
	x1+=x[1];
	int mun=stod(x1);
	if(num==mun){
		cout<<1;
	}
	else if(num!=mun){
		cout<<0<<0<<0;
		return 0;
	}
	if(num==mun){
		if(r[2]=='C' && x[2]=='D'){
			cout<<0<<0;
			return 0;
		}
		else if(r[2]=='D' && x[2]=='C'){
			cout<<0<<0;
			return 0;
		}
		else{
			cout<<1;
		}
	}
	if(num!=mun){
		cout<<0;
		return 0;
	}
	if(r[2]=='D' && x[2]=='F'){
		cout<<1;
		return 0;
	}
	if(r[2]=='F' && x[2]=='D'){
		cout<<1;
		return 0;
	}
	if(r[2]=='A' && x[2]=='B'){
		cout<<1;
		return 0;
	}
	if(r[2]=='B' && x[2]=='A'){
		cout<<1;
		return 0;
	}
	if(r[2]=='B' && x[2]=='C'){
		cout<<1;
		return 0;
	}
	if(r[2]=='C' && x[2]=='B'){
		cout<<1;
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
} 
