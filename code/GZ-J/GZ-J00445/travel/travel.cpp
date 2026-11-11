//GZ-J00445   遵义市新浦新区滨湖中学   范曾 
#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	
	if((a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')||(a2[2]=='A'&&b2[2]=='B')||(a2[2]=='A'&&b2[2]=='C')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='B'&&b2[2]=='A')||(a2[2]=='C'&&b2[2]=='A')||(a2[2]=='C'&&b2[2]=='B')){ 
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	
	if(a2[2]-b2[2]==1||b2[2]-a2[2]==1){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
}

