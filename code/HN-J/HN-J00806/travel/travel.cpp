#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char x[100],y[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a!=b){
		cout<<"0000"; 
		return 0;
	}
	else cout<<1;
	c=x[0]*10+x[1];
	d=y[0]*10+y[1];
	if(c==d)cout<<1;
	else {
		cout<<"000";return 0;
	}
	if(x[2]>='D'&&y[2]<='C'||y[2]>='D'&&x[2]<='C'){
		cout<<"00";
		return 0;
	}
	else cout<<1;
	if(x[2]-y[2]==1||y[2]-x[2]==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
