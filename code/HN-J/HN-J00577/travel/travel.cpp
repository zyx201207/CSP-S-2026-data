#include<bits/stdc++.h>
using namespace std;
long long n,m,l1,l2;
string x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>x>>m>>y;
	l1=x.size()-1;
	l2=y.size()-1;
	if(n!=m){ 
		cout<<0<<0<<0<<0;
		return 0;
	} 
	else cout<<1;
	if(x[1]==1&&x[2]!='A'&&x[2]!='B'&&x[2]!='C'&&x[2]!='D'&&x[2]!='F'&&y[1]==1&&y[2]!='A'&&y[2]!='B'&&y[2]!='C'&&y[2]!='D'&&y[2]!='F'){
		if(x[1]+x[2]!=y[1]+y[2])cout<<0;
		else cout<<1;
	}
	else if(x[1]==y[1]){
		cout<<1;
	}
	else cout<<0;
	if(x[l1]=='A'){
		if(y[l2]!='B'&&y[l2]!='C')cout<<0;
		else cout<<1;
	}
	if(x[l1]=='B'){
		if(y[l2]!='A'&&y[l2]!='C')cout<<0;
		else cout<<1;
	}
	if(x[l1]=='C'){
		if(y[l2]!='B'&&y[l2]!='A')cout<<0;
		else cout<<1;
	}
	if(x[l1]=='D'){
		if(y[l2]!='F')cout<<0;
		else cout<<1;
	}
	if(x[l1]=='F'){
		if(y[l2]!='D')cout<<0;
		else cout<<1;
	}
	if(x[l1]=='A'){
		if(y[l2]!='B')cout<<0;
		else cout<<1;
	}
	if(x[l1]=='B'){
		if(y[l2]!='A'&&y[l2]!='C')cout<<0;
		else cout<<1;
	}
	if(x[l1]=='C'){
		if(y[l2]!='B')cout<<0;
		else cout<<1;
	}
	if(x[l1]=='D'){
		if(y[l2]!='F')cout<<0;
		else cout<<1;
	}
	if(x[l1]=='F'){
		if(y[l2]!='D')cout<<0;
		else cout<<1;
	}
	
	return 0;
} 
