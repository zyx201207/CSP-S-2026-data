#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	feropen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a==x&&a!="01"&&a!="16"&&x!="01"&&x!="16"){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==y[0]&&b[1]==y[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]<='C'&&y[2]<='C')||(b[2]>'C'&&y[2]>'C')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((b[2]+1==y[2]&&b[2]!='C')||(y[2]+1==b[2]&&y[2]!='C')){
		cout<<1;
	}else cout<<0;
	return 0;
}
