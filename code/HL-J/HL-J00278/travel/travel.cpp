#include<bits/stdc++.h>
using namespace std;
string p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool x=true;
	cin>>a>>b>>c>>d;
	if(a==c&&a!="01"&&a!="16"&&c!="01"&&c!="16"){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	p1+=b[0];
	p1+=b[1];
	p2+=d[0];
	p2+=d[1];
	if(p1==p2){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if((b[2]<=67&&d[2]<=67)||b[2]>67&&d[2]>67){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		x=false;
		return 0;
	}
	if((b[2]==d[2]+1||b[2]==d[2]-1)&&x==true){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
