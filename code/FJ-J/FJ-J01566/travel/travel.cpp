#include<bits/stdc++.h>
using namespace std;
string a,x,b,y;
bool c=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("treval.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<c;
	}
	else{
		cout<<0;
		c=0;
	}
	if(x[0]==y[0]&&x[1]==y[1]){
		cout<<1;
	}
	else{
		cout<<0;
		c=0;
	}
	if(((x[2]<'D'&&y[2]<'D')||('C'<x[2]&&x[2]<='F'&&'C'<y[2]&&y[2]<='F'))){
		cout<<1;
	}
	else{
		cout<<0;
		c=0;
	}
	int d=abs((int)x[2]-y[2]);
	cout<<((d==1)?c:0);
	return 0;
}
