#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char s11=s1[2],s22=s2[2];
	if(c1==c2) {
		cout<<1;
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			cout<<1;
			if(s11<=67&&s11>=65&&s22<=67&&s22>=65||s11<=69&&s11>=68&&s22<=69&&s22>=68){
				cout<<1;
				if(s11-1==s22||s11+1==s22){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<0<<0;
			
			 
			
		}else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
	
	
	return 0;
} 
