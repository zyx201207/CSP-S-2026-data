#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
char zm1,zm2;
int flag1=0,flag3=0,flag2=0,flag4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	flag1=0;
	if(c1==c3){
		cout<<1;
		flag1=1;
	} 
	else {
		cout<<0;
		flag1=0;
	}
	
	if(flag1==1){
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			
			flag2=1;
		} else{
		
			flag2=0;
		}
	}
	if(flag2==1){
		cout<<1;
	}else{
		cout<<0;
	}
	 
	
	flag3=0;
	if(flag2==1){
		if(c2[2]<='C'&&c4[2]<='C'){
			flag3=1;
		} else if(c2[2]>'C'&&c4[2]>'C'){
			flag3=1; 
		}
	}
	if(flag3==1) cout<<1;
	else cout<<0;
	
	flag4=0;
	if(flag3==1){
		if(c2[2]-c4[2]==1||c2[2]-c4[2]==-1) flag4=1;
		else flag4=0;
	}
	if(flag4==1){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	return 0;
} 
//02 01A 02 01B

