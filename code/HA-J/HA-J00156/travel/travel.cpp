#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	//c1.length()
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	for(int i=0;i<2;i++){
		if(c1[i]!=c3[i]){
			cout<<"0000";
			return 0;
		}if(i==1){
			cout<<1;
		}
	}
	
	for(int i=0;i<2;i++){
		if(c2[i]!=c4[i]){
			cout<<"000";
			return 0;
		}if(i==1){
			cout<<1;
		}
	}
	if(c2[2]<='C'&&c4[2]<='C'){
		cout<<1;
	}else if(c2[2]>='D'&&c4[2]>='D'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
		
	if((c2[2]!='D'&&c2[2]-1==c4[2])||(c2[2]!='C'&&c2[2]+1==c4[2])){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
