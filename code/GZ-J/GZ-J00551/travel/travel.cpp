//GZ-J00551     南白初级中学-王子杰   
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans=ans+"1";
	else{
		ans="0000";
		cout<<ans;
		return 0;
	} 
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		ans=ans+"1";
		if(s1[2]-0<=67&&s2[2]-0<=67){
			ans=ans+"1";
			if(s1[2]+1==s2[2]-0||s1[2]-1==s2[2]-0) ans=ans+"1";
			else ans=ans+"0";
		} 
		else if(s1[2]-0>67&&s2[2]-0>67){
			ans=ans+"1";
			if(s1[2]+2==s2[2]-0||s1[2]-2==s2[2]-0) ans=ans+"1";
			else ans=ans+"0";
		} 
		else ans=ans+"00";
	} 
	else ans=ans+"000";
	//cout<<s1[2]-0<<" "<<s2[2]-0<<endl;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

