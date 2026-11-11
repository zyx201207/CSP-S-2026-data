#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if(b[0,1]==d[0,1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(b[2]=d[2]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(b[3]==d[3]){
		cout<<1;	
	}else{
		cout<<0;
	}
}
