#include<bits/stdc++.h>
using namespace std;

string c1,c2,c3,c4;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>c2>>c3>>c4;
	
	if(c1==c3){
		cout<<1;
	}else{
		cout<<"0000"<<endl;
		return 0;
	}
	
	bool f1=0;
	if(c2[0]==c4[0] && c2[1]==c4[1]){
		cout<<1;
		f1=1;
	}else cout<<0;
	
	bool f=0;
	if( (c2[2]>'C') == (c4[2]>'C') && f1){
		cout<<1;
		f=1;
	}else cout<<0;
	
	if( (c2[2]-1==c4[2] || c2[2]+1==c4[2]) && f){
		cout<<1<<endl;
	}else cout<<0<<endl;
	return 0;
} 
