#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,z1,s2,z2;
	cin>>s1>>z1>>s2>>z2;
	if(s1!=s2){
		cout<<"0000";
		return 0;
	}else cout<<1;
	if(z1[0]*1000+z1[1]!=z2[0]*1000+z2[1]){
		cout<<"000";
		return 0;
	}else cout<<1;
	if((z1[2]<='C'&&z2[2]<='C')||(z1[2]>='D'&&z2[2]>='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(z1[2]-z2[2])==1){
		cout<<1;
	}else cout<<0;
	return 0;
} 
