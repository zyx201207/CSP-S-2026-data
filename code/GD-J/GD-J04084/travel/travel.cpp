#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	int flat=1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2 and flat){
		cout<<"1";
	}else{
		cout<<"0000";
		flat=0;
		return 0;
	}
	string k1=s1;
	string k2=s2;
	k1=k1.erase(2,1);
	k2=k2.erase(2,1);
	if(k1==k2 and flat){
		cout<<"1";
	}else{
		cout<<"000";
		flat=0;
		return 0;
	}
	if((flat and s1[2]>='A' and s1[2] <='C' and s2[2] >='A' and s2[2] <='C') or (flat and s1[2]>='D' and s1[2] <='F' and s2[2] >='D' and s2[2] <='F')){
		cout<<"1";
	}else{
		cout<<"00";
		flat=0;
		return 0;
	}
	if((flat && s1[2]-s2[2]==1) || (flat && s2[2]-s1[2]==1)){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
} 
