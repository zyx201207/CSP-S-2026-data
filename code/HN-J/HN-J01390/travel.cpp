#include<bits/stdc++.h>
using namespace std;
bool o;
int u,n;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
		o=1;
	}
	u+=b[0]-'0'+b[1]-'0';
	n+=d[0]-'0'+d[1]-'0';
	if(!o && u==n){
		cout<<1;
	}else{
		cout<<0;
	}
	if(!o && (b[2]=='A' || b[2]=='B' || b[2]=='C') && (d[2]!='D' && d[2]!='F') && u==n){
		cout<<1;
	}else if(!o && (b[2]=='D' || b[2]=='F') && (d[2]!='A' && d[2]!='B' && d[2]!='C') && u==n){
		cout<<1;
	}else{
		cout<<0;
	}
	if(!o && b[2]=='A' && d[2]=='B'){
		cout<<1;
	}else if(!o && b[2]=='B' && (d[2]=='A' && d[2]=='C')){
		cout<<1;
	}else if(!o && b[2]=='C' && d[2]=='B'){
		cout<<1;
	}else if(!o && b[2]=='D' && d[2]=='F'){
		cout<<1;
	}else if(!o && b[2]=='F' && d[2]=='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

