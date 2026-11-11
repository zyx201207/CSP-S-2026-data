#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans;
	ans="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	    ans=ans+"1";
	    if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans=ans+"1";
			if(s1[2]>='A'&&s1[2]<='C'){
				if(s2[2]>='A'&&s2[2]<='C'){
					ans=ans+"1";
					if(abs(s1[2]-s2[2])==1) ans=ans+"1";
					else ans=ans+"0";
				}
				else  ans=ans+"00";	
			}
			else {
			if(s2[2]>='A'&&s2[2]<='C'){
				ans=ans+"00";
			}
			else ans=ans+"11";
			}
		}
		else ans="1000";		
	}
    else ans="0000";
	cout<<ans;
	return 0;
} 
