//GZ-J00582
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	while(1==1){
		if(c1[1]==c2[1]and c1[2]==c2[2]){
				cout<<1;
		}else{
			cout<<0<<0<<0<<0;
			return 0;
		}
		if(s1[1]==s2[1]and s1[0]==s2[0]){
				cout<<1;
		}else{
			cout<<0<<0<<0;
			return 0;
		}
		
		if('A'<=s1[2]<='C'and'A'<=s2[2]<='C'){
			cout<<1;
			if(s1[2]=='A'and s2[2]=='B'){
				cout<<1;
				return 0; 
			}
			if(s1[2]=='B'and s2[2]=='A'){
				cout<<1;
				return 0; 
			}
			if(s1[2]=='B'and s2[2]=='C'){
				cout<<1;
				return 0; 
			}
			if(s1[2]=='C'and s2[2]=='B'){
				cout<<1;
				return 0; 
			}
			cout<<0;
			return 0;}
		if('D'<=s1[2]<='F'and 'D'<=s2[2]<='F'){
			cout<<11;
			return 0;
			}	
		}
		cout<<00;
		return 0;
}
	
