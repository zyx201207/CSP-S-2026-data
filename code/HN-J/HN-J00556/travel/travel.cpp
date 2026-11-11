#include<iostream>
using namespace std;
int e[4][2]={{1,0},{-1,0},{0,1},{0,-1}};bool f=0,m=1,n=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b[0]==d[0] && b[1]==d[1]){
		n=1;
		cout<<1;
	}
	else cout<<0;
	if(b[2]<='C' && d[2]<='C'){
		if(n) cout<<1;
		else cout<<0;
		m=0;
	}
	else if(b[2]>'C' && d[2]>'C'){
		if(n) cout<<1;
		else cout<<0;
		m=0;
	}
	else cout<<0;
	for(int i=0;i<4;i++){
		b[1]+=e[i][0];b[2]+=e[i][1];
		if(b==d){
			f=1;
		}
	}
	if(m) f=0;
	if(f) cout<<1;
	else cout<<0;
	return 0;
} 
