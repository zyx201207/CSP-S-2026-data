#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string a;
    cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					if(s1[2]=='A'&&s2[2]=='C'){
						a="1110";
					}else if(s1[2]=='C'&&s2[2]=='A'){
						a="1110";
					}else{
						a="1111";
					}
			    }else{
					a="1100";
				}
			}else{
				if(s1[2]=='D'&&s2[2]=='E'){
					a="1111";
				}else if(s1[2]=='E'&&s2[2]=='D'){
					a="1111";
				
				}else{
					a="1100";
				}
		    }
		}else{
			a="1000";
		}
	}else{
		a="0000";
	}
	cout<<a<<endl;
	
	return 0;
}
	
	

