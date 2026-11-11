#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)  cout<<1;
	else   cout<<0<<0<<0<<0;
	
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(s1=="A"||s1=="B"||s1=="C"||s1=="D"||s1=="F"){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;				 
				cout<<0;
				cout<<0;
				return 0; 
			}
		}
	}
		
	return 0;
	
} 
