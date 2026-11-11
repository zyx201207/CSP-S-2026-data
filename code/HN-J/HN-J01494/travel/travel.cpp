#include<bits/stdc++.h>
using namespace std;
int n[8];
string c1,s1,c2,s2; 

int main(){

freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);	
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1==c2){
		n[1]=1;
		
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			n[2]=1;
			if( (s1[2]=='D'&& s2[2]=='F') || (s1[2]=='F'&& s2[2]=='D')){
					n[3]=1;
					n[4]=1;
			}
			if(s1[2]=='A'){
				if(s2[2]=='C'){
					n[3]=1;
				}
				if(s2[2]=='B' ){
					n[3]=1;
					n[4]=1;
				}	
			}
			if(s1[2]=='B'){
				if(s2[2]=='A' ||s2[2]=='C'){
					n[3]=1;
					n[4]=1;
				}
			}
		
			if(s1[2]=='C'){
				
				if(s2[2]=='A'){
					n[3]=1;	
				}
				if(s2[2]=='B'){
					n[3]=1;
					n[4]=1;
				}

			}
			
			
		}	
	}
cout<<n[1]<<n[2]<<n[3]<<n[4];
return 0;
}

