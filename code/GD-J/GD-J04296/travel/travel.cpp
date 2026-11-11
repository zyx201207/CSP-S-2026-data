#include<bits/stdc++.h>
using namespace std;
int main(){
	("travel.in",stdin);
	("travel.out",stdout);
	string c1,s1,c2,s2;
	int x1,x2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
		cout<<1;	
		if(s1[2]=='D' or s1[2]=='E') x1=1;
			else x1=0;
			if(s2[2]=='D' or s2[2]=='E') x2=1;
			else x2=0;
			if(x1==x2){
			cout<<1;
				if(x1==1) cout<<1;
				else if(x1==0){
					if(abs(s1[2]-s2[2])==1) cout<<1;
					else cout<<0;	
				}
				else cout<<0;
			} 	
			else cout<<"00";
		} 
		else cout<<"000";			
	}
	else cout<<"0000";
	return 0;
} 
