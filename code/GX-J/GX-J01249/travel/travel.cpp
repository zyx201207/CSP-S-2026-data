#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[3],s2[3];
	string c1,c2,ans="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+="1";
	}
	else{
		ans+="0";
		}
		
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+="1";
		}else{
		ans+="0";
		}
		
		if(s1[0]==s2[0]&&s1[1]==s2[1]&&(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
			ans+="1";
			}
			else if(s1[0]==s2[0]&&s1[1]==s2[1]&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				ans+="1";
				}
				else{
				ans+="0";
				}
					
		if(s1[0]==s2[0]&&s1[1]==s2[1]&&(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
			ans+="1";
			}
		else{
			if(s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]==char (s2[2]+1)&&(s1[2]!='D'&&s1[2]!='F'))||(s2[2]==char (s1[2]+1)&&(s2[2]!='D'&&s2[2]!='F')))){
			ans+="1";
		}
		else{
		ans+="0";
		}
			}
		
	cout<<ans;
return 0;
}
