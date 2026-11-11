//GZ-J00096  黔西市第二中学  熊宇晨 
#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2,s2;
int main(){
	freopen("travel.in","r","stdcin");
	freopen("travel.out","w","stdcout");
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else if(c1!="01" or c1!="16"){
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			if(s1[2]<='C' and s2[2]<='C'){
				if(s1[2]-s2[2]==1 or s2[2]-s1[2]==1){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}            
			}else if(s1[2]>='D' and s2[2]>='D'){
				cout<<"1111";
				return 0;
			}else{
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		}	
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
