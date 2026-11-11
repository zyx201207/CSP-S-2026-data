#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,c2;
	char s1,s2;
	cin>>c1>>s1>>c2>>s2;
	
if(c1==c2){
	cout<<"1";
	if(s1-s2<=5||s2-s1<=5){
		cout<<"1";
		
		if(s1-s2<=2||s2-s1<=2){
			cout<<"1";
			if(s1-s2==1||s2-s1==1){
				cout<<"1";
			}
			
			else{
				cout<<"0";
			}
		}
		else{
			cout<<"00";
		}
	}
	else{
		cout<<"000";
	}
}
else{
	cout<<"0000";
} 
	
	
	
	
	return 0;
}



 
