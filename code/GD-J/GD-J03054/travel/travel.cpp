#include <bits/stdc++.h>
using namespace std;
char a1[10],b1[10],a2[10],b2[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1[0]==a2[0]&&a1[1]==a2[1]){
		cout<<1;
	}else{
		cout<<"0000\n";
		return 0;
	}
	if(b1[0]==b2[0]&&b1[1]==b2[1]){
		cout<<1;
	}else{
		cout<<"000\n";
		return 0;
	}
	if((b1[2]<='C'&&b2[2]<='C')||(b1[2]>='D'&&b2[2]>='D')){
		cout<<1;
	}else{
		cout<<"00\n";
		return 0;
	}
	if(abs(b1[2]-b2[2])==1||((b1[2]>='D'&&b2[2]>='D')&&abs(b1[2]-b2[2])==2)){
		cout<<1<<"\n";
	}else{
		cout<<"0\n";
	}
	return 0;
}

