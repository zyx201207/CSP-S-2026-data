#include<bits/stdc++.h>
using namespace std;
long long a1,b1,a2,b2;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	if(a1==a2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	if(b1==b2){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	
	if(((c1>='A'&&c1<='C')&&(c2>='A'&&c2<='C'))||((c1>='D'&&c1<='E')&&(c2>='D'&&c2<='E'))){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if(c1+1==c2||c1-1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
