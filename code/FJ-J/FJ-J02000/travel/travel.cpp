#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b1,b;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a1[0]==b[0]&&a[1]==b[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((a1[2]<='C'&&b1[2]<='C')||(a1[2]>='D'&&b1[2]>='D')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(a1[2]-b1[2])==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
