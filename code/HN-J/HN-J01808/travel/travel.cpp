#include<bits/stdc++.h>
using namespace std;//02 01a 02 01b
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,a2,b,b2;
	cin>>a>>a2>>b>>b2;
	
	if(a==b){
		cout<<1;
	} 
	else {
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	
	if((a2[2]=='A'&&b2[2]=='B')||(a2[2]=='A'&&b2[2]=='C')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='B'&&b2[2]=='A')||(a2[2]=='C'&&b2[2]=='A')||(a2[2]=='C'&&b2[2]=='B')||(a2[2]=='D'&&b2[2]=='E')||(a2[2]=='E'&&b2[2]=='D')){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		return 0;
	}
	
	if(a2[2]-b2[2]==1||a2[2]-b2[2]==-1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
