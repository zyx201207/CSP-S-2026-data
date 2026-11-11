#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a2[2]=='F')a2[2]='E';
	if(b2[2]=='F')b2[2]='E';
	
	if(a1!=b1){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	
	for(int i=0;i<2;i++){
		if(a2[i]!=b2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	
	if((a2[2]>'C')!=(b2[2]>'C')){
		cout<<"00";
		return 0;
	}
	cout<<1;
	
	if(abs(a2[2]-b2[2])!=1){
		cout<<"0";
		return 0;
	}
	cout<<1;
	
	return 0;
} 
