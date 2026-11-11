#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	string cx1,zuo1,cx2,zuo2,a,b;
	cin>>cx1>>zuo1>>cx2>>zuo2;
	bool z=true;
	if(cx1==cx2){
		cout<<"1";
	}else{
		cout<<"0";
		z=0;
	}
	a=zuo1[0]+zuo1[1];
	b=zuo2[0]+zuo2[1];
	if((a==b)&&z){
		cout<<"1";
	}else{
		cout<<"0";
		z=0;
	}
	a=zuo1[2];
	b=zuo2[2];
	if(a>="D"&&b>="D"&&z){
		cout<<"11";
	}else if(a<"D"&&b<"D"&&z){
		cout<<"1";
		if((a=="A"&&b=="B")||(a=="B"&&b=="C")){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"00";
	}
    return 0;
}
