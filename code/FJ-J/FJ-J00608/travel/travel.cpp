#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	string ans="";
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		ans+='1';
		
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+='1';
			
			int n1,n2;
			if(s1[2]=='A')n1=1;
			else if(s1[2]=='B')n1=2;
			else if(s1[2]=='C')n1=3;
			else if(s1[2]=='D')n1=4;
			else if(s1[2]=='F')n1=5;
	
			if(s2[2]=='A')n2=1;
			else if(s2[2]=='B')n2=2;
			else if(s2[2]=='C')n2=3;
			else if(s2[2]=='D')n2=4;
			else if(s2[2]=='F')n2=5;
	
			if((n1<4&&n2<4)||(n1>3&&n2>3)){
				ans+='1';
				
				if(abs(n1-n2)==1)ans+='1';
				else ans+='0';
			}
			else{
				ans+="00";
			}
		}
		else{
			ans+="000";
		}
	}
	else{
		ans+="0000";	
	}
	
	
	cout<<ans;
	return 0;
} 
