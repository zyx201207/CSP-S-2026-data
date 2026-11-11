#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);//!!!
	freopen("travel.out","w",stdout);//!!!
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){//question1 
		
		if(s1[0]==s2[0] and s1[1]==s2[1]){//question2 
			
			if((s1[2]<='C' and s2[2]<='C') or (s1[2]>='D' and s2[2]>='D')){//question3
				
				if(abs(s1[2]-s2[2])==1){//q4
					cout<<"1111";	
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
