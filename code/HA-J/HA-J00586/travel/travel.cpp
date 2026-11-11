#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool A=1,B=1,C=1,D=1;
	if(c1!=c2){
		A=0,B=0,C=0,D=0;
	}else if(s1[1]!=s2[1]){
		B=0,C=0,D=0;
	}else if((s1[2]<='C'&&s2[2]>'C')||(s2[2]<='C'&&s1[2]>'C')){
		C=0,D=0;
	}else if(abs(s1[2]-s2[2])!=1){
		D=0;
	}
	cout<<A<<B<<C<<D;
	return 0;
}
