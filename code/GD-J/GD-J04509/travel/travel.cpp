#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,x,y,z;
	int b=0;
	cin>>s>>y>>x>>z;
	if(s[0]==x[0]&&s[1]==x[1]){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(y[0]==z[0]&&y[1]==z[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(int(y[2])<=int('C')&&int(z[2])<=int('C')||int(y[2])>int('C')&&int(z[2])>int('C')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(int(y[2])-int(z[2]))<=1){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
}
