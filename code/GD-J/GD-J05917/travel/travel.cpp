#include<bits/stdc++.h>
#include<string>
using namespace std;
string c1,s1;
string c2={},s2={};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2; 
	if(c1==s1){
	 	cout<<1;
	 	
	 	if(c2[0]==s2[0] and c2[1]==s2[1]){
	 		cout<<1;
	 		
	 		if(c2[2]=='A'||'B'||'C' && s2[2]=='A'||'B'||'C'){
	 			cout<<1;
	 			
	 			if(c2[2]=='A' and s2[2]=='B')
	 				cout<<1;
	 			else if(c2[2]=='C' and s2[2]=='B')
	 				cout<<1;
	 			else if(c2[2]=='B' and s2[2]=='C')
	 				cout<<1;
	 			else if(c2[2]=='B' and s2[2]=='A')
	 				cout<<1;
	 			
	 			else
	 				cout<<0;
	 		}else if(c2[2]=='D'||'F' && s2[2]=='D'||'F'){
	 			cout<<1<<1;
			}else 
	 			cout<<0;
		}else
			cout<<0<<0<<0;
	}else
		cout<<0<<0<<0<<0;
	return 0;
} 
