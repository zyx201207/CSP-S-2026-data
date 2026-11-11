#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	int f=1;
	for(int i=0;i<2;i++){
		if(a1[i]!=b1[i]){
			cout<<"0000";
			return 0;
		}
	}
	if(f){
		cout<<"1";
	}
	for(int i=0;i<2;i++){
		if(a2[i]!=b2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if((a2[2]=='A'&&b2[2]=='B')||(a2[2]=='B'&&b2[2]=='A')||(a2[2]=='A'&&b2[2]=='C')||(a2[2]=='C'&&b2[2]=='A')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='C'&&b2[2]=='B')||(a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')){
		cout<<"1";
		if((a2[2]=='A'&&b2[2]=='B')||(a2[2]=='B'&&b2[2]=='A')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='C'&&b2[2]=='B')||(a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')){
			cout<<"1";
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
