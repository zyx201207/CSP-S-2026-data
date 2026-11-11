#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f;
string res="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		res[0]='1';
		
		for(int i=0;i<2;i++){
			if(s1[i]==s2[i])f=1;
			else f=0;
		}	
		
		if(f){
			
			res[1]='1';
			
			if((s1[2]>='D' and s2[2]>='D') or (s1[2]<='C' and s2[2]<='C')){
				res[2]='1';
				
				
				
				if(s1[2]-s2[2]==1){
					res[3]='1';
					cout<<res;
				}
				
				
				
				else if(s2[2]-s1[2]==1){
					res[3]='1';
					cout<<res;
				}
				
				
				else cout<<res;
			}
			
			
			else cout<<res;
		}
		
		else cout<<res;
	}
	
	else cout<<res;
	
	return 0;
}
