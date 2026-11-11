#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		int u1,u2;
		char w1=s1[2];
		char w2=s2[2];
	    if(s1[0]==s2[0]&&s1[1]==s2[1]){
	    	
	    if(w1=='F'||w1=='D'){
	    	if(w2=='F'||w2=='D'){
	    		cout<<"1111";
	    		return 0;
			}
		}else{
			if(w2=='F'||w2=='D'){
				cout<<"1100";
				return 0;
			}else{
				if(w1+1==w2||w1-1==w2){
					
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}
			
		}
	     
		}else{
			cout<<"1000";
			return 0;
		}
	}
		
	return 0;
}
