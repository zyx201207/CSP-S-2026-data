#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	int k1=0,k2=0;
	k1=(s1[0]-48)*10+(s1[1]-48);
	k2=(s2[0]-48)*10+(s2[1]-48);
	if(k1==k2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]>='A' && s1[2]<='C'){
		if(s2[2]>='A' && s2[2]<='C'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(s1[2]>='D' && s1[2]<='F'){
		if(s2[2]>='D' && s2[2]<='F'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	if(abs(s1[2]-s2[2])==1){
		if(s1[2]=='C' &&  s2[2]=='D'){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	else{
		if(s1[2]=='D' && s2[2]=='F'){
			cout<<1;
		}
		else if(s2[2]=='D' && s1[2]=='F'){
			cout<<1;
		}
		else cout<<0;
	}
	return 0;
}
