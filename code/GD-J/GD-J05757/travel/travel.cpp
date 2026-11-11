#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string ans="0000";
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		ans[0]='1';
		if(((s1[2]-s2[2]>1)||(-1*(s1[2]-s2[2])>1))&&s1[2]!='C'&&s2[2]!='D'){
			ans[2]='0';
		}else ans[2]='1';
		if(s1[2]=='C'&&s2[2]=='D'){
			ans[2]='0';
		}
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]='1';//cout<<ans;
			if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
				ans[2]='1';ans[3]='1';
			}else {
			if(s2[2]=='B'&&(s1[2]=='A'||s1[2]=='C')){
				ans[2]='1';ans[3]='1';
			}else if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
				ans[2]='1';
				ans[3]='1';
			}	
			
			
		 
		
			
	
	
}}}
cout<<ans;
//[s1[2]=="D"&&s2[2]=="F"]||[s2[2]=="D"&&s1[2]=="F"]
    return 0;
}
//'B''A''C'

