#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char R1[2],R2[3],X1[2],X2[3];
	cin>>R1>>R2>>X1>>X2;
    if(R1[0]==X1[0]&&R1[1]==X1[1]){
    	cout<<"1";
    	if(R2[0]==X2[0]&&R2[1]==X2[1]){
    		cout<<"1";
    		if(((R2[2]==65||R2[2]==66||R2[2]==67)&&(X2[2]==65||X2[2]==66||X2[2]==67))||((R2[2]==68||R2[2]==70)&&(X2[2]==68||X2[2]==70))){
    			cout<<"1";
    			if((((R2[2]==65||R2[2]==66)&&(X2[2]==65||X2[2]==66))||((R2[2]==66||R2[2]==67)&&(X2[2]==66||X2[2]==67)))||((R2[2]==68||R2[2]==70)&&(X2[2]==68||X2[2]==70))){
    				cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 


