#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	string isf="";
	
	if(s1==c1)isf+="1";
	else{
		isf+="000";
		if(s2[2]<='C'&&c2[2]<='C'){
			if(s2[2]+1==c2[2]||c2[2]+1==s2[2]||s2[2]-1==c2[2]||c2[2]-1==s2[2]){
				isf+="1";
				cout<<isf;
				return 0;
			}
			else{
				isf+="0";cout<<isf;
				return 0;
			} 
		}
		else if(s2[2]>='D'&&c2[2]>='D'){
			if(s2[2]+1==c2[2]||c2[2]+1==s2[2]||s2[2]-1==c2[2]||c2[2]-1==s2[2]){
				isf+="1";cout<<isf;
				return 0;
			}
			else{
				isf+="0";cout<<isf;
				return 0;
			} 
		}
		else{
			isf+="0";cout<<isf;
			return 0;
		}
		return 0;
	}
	
	
	bool isa=0;
	if(s2[0]==c2[0]&&s2[1]==c2[1]){
		isf+="1";
		isa=1;
	}
	else isf+="0";
	
	bool isb=0;
	if(isa==0)isf+="0";
	else if(s2[2]<='C'&&c2[2]<='C'||s2[2]>='D'&&c2[2]>='D'){
		isf+="1";
		isb=1;
	}
	else isf+="0";
	
	if(isa==1&&isb==1){
		if(s2[2]+1==c2[2]||c2[2]+1==s2[2]||s2[2]-1==c2[2]||c2[2]-1==s2[2]){
			isf+="1";
			cout<<isf;
			return 0;
		}
		else{
			isf+="0";cout<<isf;
			return 0;
		} 
	}
	else{
		isf+="0";cout<<isf;
		return 0;
	}
	return 0;
}
