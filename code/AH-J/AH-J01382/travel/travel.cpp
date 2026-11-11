#include<bits/stdc++.h>
using namespace std;
string r,r1,x1,x;
int main(){
	freopen("travel.in","r",sidin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>r1>>r;
	cin>>x1>>x;
	bool n;
	if(r1==x1){
		n=1;
		cout<<"1";
	}else{
		n=0;
		cout<<"0";
	}
	bool y;
	if(r[0]==x[0]&&r[1]==x[1]&&n){
		y=1;
		cout<<"1";
	}else{
		y=0;
		cout<<"0";
	}
	bool l;
	if(r[2]<='C'&&x[2]<='C'&&n&&y||r[2]=='F'&&x[2]=='D'&&n&&y||r[2]=='D'&&x[2]=='F'&&n&&y){
		l=1;
		cout<<"1";
	}else{
		l=0;
		cout<<"0";
	}
	int a=r[2],b=x[2];
	if(l&&n&&y&&a+1==b||l&&n&&y&&b+1==a){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
