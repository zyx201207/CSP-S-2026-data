#include<iostream>
#include<cmath>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if(s1[2]=='F' || s1[2]=='D'){
		if(s2[2]!='F' && s2[2]!='D'){
			cout<<"00";
			return 0;
		}
	}else{
		if(s2[2]!='A' && s2[2]!='B' && s2[2]!='C'){
			cout<<"00";
			return 0;
		}
	}
	cout<<1;
	if(s1[2]=='F' || s1[2]=='D'){
		if(s2[2]!='F' && s2[2]!='D'){
			cout<<"0";
			return 0;
		}
	}else{
		if(abs(s1[2]-s2[2])!=1){
			cout<<0;
			return 0;
		}
	}	
	cout<<1;
	return 0;
} 
