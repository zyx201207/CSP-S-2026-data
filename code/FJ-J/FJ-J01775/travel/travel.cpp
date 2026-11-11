#include<bits/stdc++.h>
using namespace std;
	

int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r,x,R,X;
	cin>>R>>r>>X>>x;
	int a=0;
	if(R[0]==X[0] && R[1]==X[1]){
		cout<<1;
		a++;
	}else{
		cout<<0;
	}
	if(r[0]==x[0] && r[1]==x[1] && a==1){
		cout<<1;
		a++;
	}else{
		cout<<0;
	}
	
	if(((r[2]<4 && x[2]<4) || (r[2]>4 && x[2]>4)) && a==2){
		cout<<1;
		a++;
	}else{
		cout<<0;
	}
	if(r[2]=='A'){
		r[2]=1;
	}
	if(r[2]=='B'){
		r[2]=2;
	}
	if(r[2]=='C'){
		r[2]=3;
	}
	if(r[2]=='D'){
		r[2]=5;
	}
	if(r[2]=='F'){
		r[2]=6;
	}
	if(x[2]=='A'){
		x[2]=1;
	}
	if(x[2]=='B'){
		x[2]=2;
	}
	if(x[2]=='C'){
		x[2]=3;
	}
	if(x[2]=='D'){
		x[2]=5;
	}
	if(x[2]=='F'){
		x[2]=6;
	}
	if(a==3){
		if(r[2]>4 && x[2]>4){
			cout<<1;
		}else if(r[2]==2 || x[2]==2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	
	
	
	return 0;
}


