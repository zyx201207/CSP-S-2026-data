#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;string a2,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<1;
	else{
	    cout<<"0000";
	    return 0;
	}
	int a3=(a2[0]-'0')*10+(a2[1]-'0');
	int b3=(b2[0]-'0')*10+(b2[1]-'0');
	if(a3==b3) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(!(a2[2]<='C' ^ b2[2]<='C')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(a2[2]-b2[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
