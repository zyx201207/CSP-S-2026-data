#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a[0]==x[0]&&a[1]==x[1]){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==y[0]&&b[1]==y[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(b[2]<='C'&&y[2]<='C'){
		cout<<1;
	}else if(b[2]>'C'&&y[2]>'C'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-y[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
