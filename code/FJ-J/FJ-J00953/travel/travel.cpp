#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_1,c_2,s_1,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<1;
		if(s_1[0]==s_2[0] && s_1[1]==s_2[1]){
			cout<<1; 
			if(s_1[2]<='C' && s_1[2]>='A' && s_2[2]<='C' && s_2[2]>='A' ){
				cout<<1;
				if((s_1[2]-s_2[2]==1) || (s_1[2]-s_2[2]==-1)){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(s_1[2]<='F' && s_1[2]>='D' && s_2[2]<='F' && s_2[2]>='D'){
				cout<<1;
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	
	
	
	
	
	return 0;
} 
