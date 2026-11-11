#include<bits/stdc++.h> 
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	int xoo=0,xtt=0;
	char zo[3],zt[3];
	cin>>xoo>>zo>>xtt>>zt;
	if(xoo-xtt==0){
	cout<<"1";
	}
		

	else{
	
		cout<<"0";}
		
	if((zo[1]==zt[1]&&zo[0]==zt[0])&&xoo-xtt==0){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	if((zo[1]==zt[1]&&zo[0]==zt[0]&&xoo-xtt==0)&&(zo[2]<68&&zt[2]<68)||(zo[2]>67&&zt[2]>67)){
		cout<<1;
	}
	else{
		cout<<0; 
	}
	
	
	
	
	if(((zo[1]==zt[1]&&zo[0]==zt[0]&&xoo-xtt==0)&&zo[2]-zt[2]==1||zt[2]-zo[2]==1)&&((zo[2]!='C'&&zt[2]!='D')||(zo[2]!='D'&&zt[2]!='C'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0; 
} 
