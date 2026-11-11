#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	int a=0,x=0,y=0,z=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;		
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			x=1;
			if(s1[2]<='C'&&s2[2]<='C'){
				y=1;
				if(s1[2]=='B'||s2[2]=='B'){
					z=1;
					
				}
			}if('D'<=s1[2]&&'D'<=s2[2]){
				y=1;
				z=1;
			}
		}
	}
	cout<<a<<x<<y<<z;	
	
	return 0;
} 
