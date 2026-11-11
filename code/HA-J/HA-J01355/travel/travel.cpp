#include<bits/stdc++.h>
using namespace std;
string cc1,dd1,cc2,dd2,a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cc1>>cc2>>dd1>>dd2;
	if(cc1[0]==dd1[0] && cc1[1]==dd1[1]){
		a+='1';
	}else{
		a+='0';
	}
	if(cc2[0]==dd2[0] && cc2[1]==dd2[1] && a[0]=='1'){
		a+='1';
	}else{
		a+='0';
	}
	if(cc2[2]<='C' && dd2[2]<='C' && a[1]=='1'){
		a+='1';
	}else if(cc2[2]>'C' && dd2[2]>'C' && a[1]=='1'){
		a+='1';
	}else{
		a+='0';
	}
	if(cc2[2]==dd2[2]+1 && cc2[2]!='D' && a[1]=='1'){
		a+='1';
	}else if(cc2[2]==dd2[2]-1 && cc2[2]!='C' && a[1]=='1'){
		a+='1';
	}else{
		a+='0';
	}
	cout<<a;
	return 0;
}
