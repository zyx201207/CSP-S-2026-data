#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,a1,b1;
	int flag=1;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
	}else{
		cout<<0;
		flag=0;
	}
	for(int i=0;i<=1;i++){
		if(a1[i]!=b1[i] || flag==0){
			flag=0;
			cout<<0;
			break;
		}
	}
	if(flag) cout<<1;
	if(flag&&a1[2]>='A'&&a1[2]<='C'&&b1[2]>='A'&&b1[2]<='C'){
		cout<<1;
	}else if(flag&&a1[2]=='D'&&a1[2]=='F'&&b1[2]=='D'&&b1[2]=='F'){
		cout<<1;
	}else{
		cout<<0;
		flag=0;
	}
	if(flag&& (char(a1[2]-1)==b1[2] || char(a1[2]+1)==b1[2]) ){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
