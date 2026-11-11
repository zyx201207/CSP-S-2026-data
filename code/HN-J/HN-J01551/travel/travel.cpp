#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1!=a2){
		cout<<"0000";
		return 0;
	}
	int a;
	
	if(b1[0]==b2[0] && b1[1]==b2[1]){
		
		if(b1[2]>='D' && b2[2]>='D' || b1[2]<='C' && b2[2]<='C'){
			
			if(b1[2]=='D' && b2[2]=='F' ||b1[2]=='D' && b2[1]=='F'){
				cout<<1111;	
			}
			else{
				a=b1[2]-b2[2];
			    if(abs(a)==1){
				    cout<<1111;
				    return 0;
			    }
			    else{
				    cout<<1110;
			        return 0;
			   }
			} 
		}
		else{
			cout<<1100;
			return 0;	
		}
		
	}
	else{
		cout<<1000;
	    return 0;
	}
	return 0;
} 
