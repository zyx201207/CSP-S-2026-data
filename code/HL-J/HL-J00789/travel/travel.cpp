#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a;
	string c;
	int b;
	string d;
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(c[0]==d[0]&&c[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	int x=int(c[2]);
	int y=int(d[2]);
	//cout<<x<<y;
	if(x>=65&&x<=67&&y>=65&&y<=67){
		cout<<1;
	}
	else if(x>=68&&x<=70&&y>=68&&y<=70){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	//char m=C,n=D,o=F;
	//cout<<int(m)<<" "<<int(n)<<" "<<int(o);
	if(x+1==y||x-1==y){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}