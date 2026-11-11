#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int f1,f2;
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		cout<<"0000";
		return 0;	
	}else{
		cout<<"1";
	} 
	for(int i=0;i<=1;i++){
		if(a2[i]!=b2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if(a2[2]>='D'&&a2[2]<='F'){
		f2=2;
	}else{
		f2=1;
	}
	if(b2[2]>='D'&&b2[2]<='F'){
		f1=2;
	}else{
		f1=1;
	}
	if(f1!=f2){
		cout<<"00";
		return 0;
	}else{
		cout<<"1";
	}
	if(a2[2]-b2[2]==1 || b2[2]-a2[2]==1) cout<<"1";
	else cout<<"0";
	return 0;
} 
