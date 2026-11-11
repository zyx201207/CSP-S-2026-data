//GZ-J00049 贵阳市第一中学 吴昊然 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx1,cx2,zw1,zw2,ans="";
	cin>>cx1>>zw1>>cx2>>zw2;
	string ps1,ps2;
	char ls1,ls2;
	ps1=zw1[0]+zw1[1],ps2=zw2[0]+zw2[1];
	ls1=zw1[2],ls2=zw2[2];
	if(cx1!=cx2){
		cout<<"0000";
	}else if(ps1!=ps2){
		cout<<"1000";
	}else if((ls1>='D'&&ls2<='C')||(ls2>='D'&&ls1<='C')){
		cout<<"1100";
	}else if(abs(ls1-ls2)!=1){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}
