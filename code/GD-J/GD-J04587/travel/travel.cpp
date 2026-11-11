#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string c1,c2,s1,s2,ans,t="ABCDF";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(nullptr);
	cin>>c1>>s1;
	cin>>c2>>s2;
	
	if(c1==c2){ans+="1";}
	else{ans+="0";}
	
	if(ans[0]=='0'){ans+="0";} 
	else if(s1[0]==s2[0]&&s1[1]==s2[1]){ans+="1";}
	else{ans+="0";}
	
	if(ans[1]=='0'){ans+="0";}
	else if((s1[2]==t[0]||s1[2]==t[1]||s1[2]==t[2])&&(s2[2]==t[0]||s2[2]==t[1]||s2[2]==t[2])){ans+="1";}
	else if((s1[2]==t[3]||s1[2]==t[4])&&(s2[2]==t[3]||s2[2]==t[4])){ans+="1";}
	else{ans+="0";}
	
	if(ans[2]=='0'){ans+="0";}
	else if((s1[2]==t[0]&&s2[2]==t[1])||(s1[2]==t[1]&&s2[2]==t[2])||(s1[2]==t[1]&&s2[2]==t[0])||(s1[2]=t[2]&&s2[2]==t[1])){ans+="1";}
	else if((s1[2]==t[4]&&s2[2]==t[3])||(s1[2]==t[3]&&s2[2]==t[4])){ans+="1";}
	else{ans+="0";}
	
	cout<<ans;
	return 0;
}
