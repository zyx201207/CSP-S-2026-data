//GZ-J00179 遵义市红花岗区第十三小学 郭璟岩
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	string a="",b="";
	a+=s2[0];
	a+=s2[1];
	b+=s4[0];
	b+=s4[1];
	if(a==b){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	a="";
	b="";
	a+=s2[2];
	b+=s4[2];
	if((a=="D"&&b=="F")||(a=="F"&&b=="D")||(a=="A"&&b=="B")||(a=="A"&&b=="C")||(a=="B"&&b=="C")||(a=="B"&&b=="A")||(a=="C"&&b=="A")||(a=="C"&&b=="B")){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((a=="D"&&b=="F")||(a=="F"&&b=="D")||(a=="A"&&b=="B")||(a=="B"&&b=="A")||(a=="B"&&b=="C")||(a=="C"&&b=="B")){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

