#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>x>>b>>y;
	int p=0,q=0,o=0;
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<1;
		p=1;
	}else{
		cout<<0;
	}
	if(p==0){
		cout<<0<<0<<0;
		return 0;
	}
	if(x[0]==y[0]&&x[1]==y[1]){
		cout<<1;
		q=1;
	}else{
		cout<<0;
	}
	if(q==0){
		cout<<0<<0;
		return 0;
	}
	if(x[2]=='A'&&y[2]=='B'||x[2]=='B'&&y[2]=='C'||x[2]=='B'&&y[2]=='A'||x[2]=='C'&&y[2]=='B'||x[2]=='D'&&y[2]=='F'||x[2]=='F'&&y[2]=='D'){
		o=1;
		cout<<1<<1;
	}else if(x[2]=='A'&&y[2]=='C'||x[2]=='C'&&y[2]=='A'){
		o=1;
		cout<<1<<0;
	}
	if(o==0){
		cout<<0<<0;
	}
	return 0;
}
