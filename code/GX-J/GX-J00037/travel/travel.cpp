#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","o",stdout);
	int a1;
	cin>>a1;
	string s1;
	cin>>s1;
	int a2;
	cin>>a2;
	string s2;
	cin>>s2;
	int b1,b2;
	b1=s1[0]-48;
	b1=b1*10+s1[1]-48;
	b2=s2[0]-48;
	b2=b2*10+s2[1]-48;
	if(a1==a2){
		cout<<1;
		if(b1==b2){
			cout<<1;
			b1=s1[2]-64;
			b2=s2[2]-64;
			int b3;
			b3=b1+b2;
			if(b3>=14||b3<=6){
				cout<<1;
			}else{
				
				cout<<0;
			}
		}else{
			
			cout<<00;
		}
	}else{
	
		cout<<000;
	}
	
	
	
	
	if(b2-b1==1&&b1!=3&&b2!=4){
		
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	
	return 0;
}
