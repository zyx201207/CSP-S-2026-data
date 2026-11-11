//GZ-J00373 兴义市弘毅中学 梁羽辰  
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
char r[2],x[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else ans+='1';
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		ans+='1';	
	}else ans+='0';
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
		if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C') ans+='1';
	}else ans+='0';
	if(s1[2]=='D' || s1[2]=='F'){
		if(s2[2]=='D' || s2[2]=='F') ans+='1';
	}else ans+='0';
	if(s1[2]=='A' && s2[2]=='B'){
		ans+='2';
	}else if(s1[2]=='B' && s2[2]=='A'){
		ans+='1';
	}else if(s1[2]=='B' && s2[2]=='C'){
		ans+='1';
	}else if(s1[2]=='C' && s2[2]=='B'){
		ans+='1';
	}else if(s1[2]=='F' && s2[2]=='D'){
		ans+='1';
	}else if(s1[2]=='D' && s2[2]=='F'){
		ans+='1';
	}else ans+='0';
	cout<<ans;
	return 0;
} 
