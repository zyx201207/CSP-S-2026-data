#include<bits/stdc++.h>
using namespace std; 
string c1,c2,c3,c4;
int a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	int x=0;
	for(int i=1;i<=2;i++){
		if(c1[x]>='0'&&c1[x]<='9'){
			a1=a1*10+int(c1[x]-'0');
		}	
		else{
			break;
		}
		x++;
	} 
	x=0;
	while(1){
		if(c2[x]>='0'&&c2[x]<='9'){
			a2=a2*10+int(c2[x]-'0');
		}	
		else{
			break;
		}
		x++;
	} 
	x=0;
	for(int i=1;i<=2;i++){
		if(c3[x]>='0'&&c3[x]<='9'){
			a3=a3*10+int(c3[x]-'0');
		}	
		else{
			break;
		}
		x++;
	} 
	x=0;
	while(1){
		if(c4[x]>='0'&&c4[x]<='9'){
			a4=a4*10+int(c4[x]-'0');
		}	
		else{
			break;
		}
		x++;
	} 
	if(a1==a3){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2==a4){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(((c2[2]>='A'&&c2[2]<='C')&&(c4[2]>='A'&&c4[2]<='C'))||((c2[2]=='D'||c2[2]=='F')&&(c4[2]=='D'&&c4[2]=='F'))){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(c2[2]!='D'&&c2[2]!='F'){
		if((c2[2]+1==c4[2]||c2[2]-1==c4[2])&&c2[2]!='D'&&c4[2]!='D'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		if((c2[2]=='D'&&c4[2]=='F')||(c2[2]=='F'&&c4[2]=='D')){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
