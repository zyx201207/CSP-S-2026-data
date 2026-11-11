#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1[0]==b1[0] && a1[1]==b1[1]){
		
	}
	else{
		cout<<"0000";
		return 0;
		
	}
	if(a2[0]==b2[0] && a2[1]==b2[1]){
		
	}
	else{
		cout<<"1000";
		return 0;
	}
	if(a2[2]<='C'){
		if(a2[2]<='A'){
			if('C'<=b2[2]){
				if(b2[2]<='A'){
					
				}
			}
		}
	}
	else if(a2[2]<='F'){
		if(a2[2]<='D'){
			if(b2[2]<='F'){
				if(b2[2]<='D'){
					
				}
			}
		}	
	}
	else{
		cout<<"1100";
		return 0;
	}
	if('A'<=a2[2] && a2[2]<='C'){
			if('A'<=b2[2] && b2[2]<='C'){
					if(a2[2]+1==b2[2] || a2[2]-1==b2[3]){
						
					}
			}
	}	
	else if('D'<=a2[2] && a2[2]<='F'){
			if('D'<=b2[2] && b2[2]<='F'){
				if(a2[2]+2==b2[2] || a2[2]-2==b2[3]){
					
				}
			}
	}
	else{
		cout<<"1110";
		return 0;
	} 
	cout<<"1111";
	return 0;
}
