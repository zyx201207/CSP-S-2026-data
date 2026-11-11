#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="";
bool flag=1,f2=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans=ans+"1";
	}else{
		ans=ans+"0";
		flag=0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1] && flag==1){
		ans=ans+"1";
	}else{
		ans=ans+"0";
		f2=0;
	}
	if((('A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='C')   || ('D'<=s1[2]&& s1[2]<='F' && 'D'<=s2[2]&& s2[2]<='F') )&& flag==1 && f2==1){
		ans=ans+"1";
	}else{
		ans=ans+"0";
	}	
	if(abs(s1[2]-s2[2])==1 && f2==1 && (s1[2]!='C' && s2[2]!='D') && (s2[2]!='C' && s1[2]!='D')){
		ans=ans+"1";
	}else{
		ans=ans+"0";
	}
	cout<<ans;
	return 0;
}
