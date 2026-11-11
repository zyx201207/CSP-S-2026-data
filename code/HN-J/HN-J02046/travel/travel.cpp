#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char R1,X1;
	char R2[2],X2[2];
	cin>>R1;
	for(int i=0;i<2;i++){
		cin>>R2[i];
	}
	cin>>X1;
	for(int i=0;i<2;i++){
		cin>>X2[i];
	}
	if(R1==X1){
		cout<<"1";
		if(R2[0]==X2[0]){
			cout<<"1";
			if((R2[1]=='A'||R2[1]=='B'||R2[1]=='C')&&(X2[1]=='A'||X2[1]=='B'||X2[1]=='C')){
				cout<<"1";
			}else
			{
			if((R2[1]=='D'||R2[1]=='E')&&(X2[1]=='D'||X2[1]=='E')){
				cout<<"1";
			}
			} 
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
