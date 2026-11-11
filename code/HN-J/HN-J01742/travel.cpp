#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	int flag=1,flag2=1;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
	}
	else{
		cout<<0;
		flag=0;
	}
	if(c2[0]==c4[0]&&c2[1]==c4[1]&&flag){
		cout<<1;
	}
	else{
		cout<<0;
		flag2=0;
	}
	int flag3=1;
	if(((c2[2]>'C'&&c4[2]>'C')||(c2[2]<='C'&&c4[2]<='C'))&&flag2){
		cout<<1;
	}
	else{
		cout<<0;
		flag3=0;
	}	
	if((c2[2]-c4[2]==1||c4[2]-c2[2]==1)&&flag3){
		cout<<1;
	}	
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
