#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
		if(s1[1]==s2[1]&&s1[0]==s2[0]){
			cout<<"1";
			
			if(s1[2]<='C'&&s2[2]<='C'){
				if((s1[2]-s2[2]<=2&&s1[2]-s2[2]>=0)||(s2[2]-s1[2]<=2&&s2[2]-s1[2]>=0)){
					cout<<"1";
					if((s1[2]-s2[2]<=1&&s1[2]-s2[2]>=0)||(s2[2]-s1[2]<=1&&s2[2]-s1[2]>=0)){
						cout<<"1";
					}else{cout<<"0";}
				}else{cout<<"00";}
			}else if(s1[2]>='C'&&s2[2]>='C'){
				if(s1[2]-s2[2]==2||s2[2]-s1[2]==2){
					cout<<"11";	
				}else{cout<<"00";}
			}
			
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
