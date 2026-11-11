#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	string x;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		x = "1";
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		x = "11";
	}else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		x = "10";
	}else{
		x = "10";
	}
    
    if(x=="11"){
    	if(s1[2]='A'){
			if(s2[2]='B'){
				x="1111";
			}else if(s2[2]='C'){
				x="1110";
			}else if(s2[2]='D'){
				x="1100";
			}else if(s2[2]='E'){
				x="1100";
			}else{
				x="1100";
			}
		}
    	if(s1[2]='B'){
			if(s2[2]='A'){
				x="1111";
			}else if(s2[2]='C'){
				x="1111";
			}else if(s2[2]='D'){
				x="1100";
			}else if(s2[2]='E'){
				x="1100";
			}else{
				x="1100";
			}
		}	
    	if(s1[2]='C'){
			if(s2[2]='B'){
				x="1111";
			}else if(s2[2]='A'){
				x="1110";
			}else if(s2[2]='D'){
				x="1100";
			}else if(s2[2]='E'){
				x="1100";
			}else{
				x="1100";
			}
		}
    	if(s1[2]='D'){
			if(s2[2]='E'){
				x="1111";
			}else if(s2[2]='C'){
				x="1100";
			}else if(s2[2]='B'){
				x="1100";
			}else if(s2[2]='A'){
				x="1100";
			}else{
				x="1100";
			}	
		}	
	}
	
	if(x=="10"){
		cout<<"1000";
		return 0; 
	}
	cout<<x;
	return 0;
}
