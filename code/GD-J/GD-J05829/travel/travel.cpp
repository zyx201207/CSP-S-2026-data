#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,a1,b1;
	cin>>a>>b>>a1>>b1;
	for(int i=0;i<2;i++){
		if(a[i]!=a1[i]){
			cout<<0<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<2;i++){
		if(b[i]!=b1[i]){
			cout<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	if(b[2]-'A'<3&&b1[2]-'A'<3){
		cout<<1;
	}else if(b[2]-'A'>=3&&b1[2]-'A'>=3){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(abs(b[2]-b1[2])==1){
		if(b[2]=='C'&&b1[2]=='D'){
			cout<<0;
		}else if(b1[2]=='C'&&b[2]=='D'){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		cout<<0;
	}
} 
