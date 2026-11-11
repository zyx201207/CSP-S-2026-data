#include<bits/stdc++.h>
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
	int f=0;
	for(int i=0;i<2;i++){
		if(s2[i]!=s4[i]){
			f=1;
			break;
		}
	}
	if(f==0){
		cout<<'1';
		if(s2[2]<='C' && s4[2]<='C' && s2[2]>='A' && s4[2]>='A'){
			cout<<'1';
		}else if((s2[2]=='D' || s2[2]=='F') && (s4[2]=='D' || s4[2]=='F')){
			cout<<'1';
		}else{
			cout<<'0';
		}
		if(abs(s2[2]-s4[2])==1){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}else{
		cout<<"000";
	}
	
	return 0;
}
