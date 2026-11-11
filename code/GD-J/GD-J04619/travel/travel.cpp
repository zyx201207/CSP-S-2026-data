#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f3=0;
	if(c1==c2){
		ans+="1";
		f3=1;
	}
	else{
		ans+="0"; 
	}
	bool f1=0;
	if(f3&&s1[0]==s2[0]&&s1[1]==s2[1]){
		ans+="1"; 
		f1=1;
	}
	else {
		ans+="0";
	}
	bool f=0;
	if(f&&('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'))
	{
	
		ans+="1";
		f=1;
	}
	else{
		ans+="0";
		 
	} 
	if(f){
		if(abs(s1[2]-s2[2])==1){
			ans+="1";
		}
		else ans+="0";
	}
	else ans+="0";
	cout<<ans;
	return 0;
} 
