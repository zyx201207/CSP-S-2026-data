#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,ans="";
int k1,k2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')k1=1;
	else k1=2;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')k2=1;
	else k2=2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])ans[0]='1';
	else {
		for(int i=0;i<4;i++)ans[i]='0';
	}
	if(ans[0]=='1'&&s1[0]==s2[0]&&s1[1]==s2[1]){
		ans[1]='1';
	}
	else ans[1]='0';
	if(ans[1]=='1'){
		if(k1==k2&&k1==2){
			ans[2]='1';ans[3]='1';
		}
		else if(k1==k2&&k1==1){
			ans[2]='1';
			if(abs(s1[2]-s2[2])==1){
				ans[3]='1';
			}
			else ans[3]='0';
		}
		else{
			ans[2]='0';ans[3]='0';
		}
	}
	for(int i=0;i<4;i++)cout<<ans[i];
	fclose(stdin);
	fclose(stdout);
} 
