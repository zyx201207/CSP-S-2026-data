/*GZ-j00634 ·ë»¸î£ */
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans=ans+'1';
	}else{
		ans=ans+"0000";
		cout<<ans;
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		ans=ans+'1';
	}else{
		ans=ans+"000";
		cout<<ans;
		return 0;
	}
	
	if(int(s1[2])>=65&&int(s1[2])<=67 && s2[2]>=65&&int(s2[2])<=67||
	   int(s1[2])>=68&&int(s1[2])<=69 && s2[2]>=68&&int(s2[2])<=69){
		ans=ans+'1';
	}else{
		ans=ans+"00";
		cout<<ans;
		return 0;
	}
	
	if(s1[2]+1==s2[2]||s1[2]==s2[2]+1){
		ans=ans+'1';
		cout<<ans;
		return 0;
	}else{
		ans=ans+'0';
		cout<<ans;
		return 0;
	}
}
