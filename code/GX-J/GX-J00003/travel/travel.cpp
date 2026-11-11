#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c,z,cc,zz;
cin>>c>>z>>cc>>zz;
if(c==cc&&c!="01"&&c!="16"&&cc!="01"&&cc!="16"){
	cout<<"1";
	if(z=="01A"||z=="01B"||z=="01C"||z=="01D"||z=="01F"&&zz=="01A"||zz=="01B"||zz=="01C"||zz=="01D"||zz=="01F"||z=="02A"||z=="02B"||z=="02C"||z=="02D"||z=="02F"&&zz=="02A"||zz=="02B"||zz=="02C"||zz=="02D"||zz=="02F"||z=="03A"||z=="03B"||z=="03C"||z=="03D"||z=="03F"&&zz=="03A"||zz=="03B"||zz=="03C"||zz=="03D"||zz=="03F"||z=="04A"||z=="04B"||z=="04C"||z=="04D"||z=="04F"&&zz=="04A"||zz=="04B"||zz=="04C"||zz=="04D"||zz=="04F"||z=="05A"||z=="05B"||z=="05C"||z=="05D"||z=="05F"&&zz=="05A"||zz=="05B"||zz=="05C"||zz=="05D"||zz=="05F"||z=="06A"||z=="06B"||z=="06C"||z=="06D"||z=="06F"&&zz=="06A"||zz=="06B"||zz=="06C"||zz=="06D"||zz=="06F"){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(z=="01A"||z=="01B"||z=="01C"&&zz=="01A"||z=="01B"||z=="01C"){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(z=="01A"&&zz=="01B"||z=="01B"&&zz=="01C"||z=="01c"&&zz=="01D"||z=="01D"&&zz=="01F"){
		cout<<"1";
	}
	
}else{
	cout<<"0000";
}
fclose(stdin);
fclose(stdout);
return 0;
}
