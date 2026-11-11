#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(s1[0]-'0')*10+s1[1]-'0';
	b=(s2[0]-'0')*10+s2[1]-'0';
	if (c1==c2){
		ans+='1';
	}else{
		ans+='0';
	}
	if (a==b&&ans[0]=='1'){
		ans+='1';
	}else{
		ans+='0';
	}
	if (ans[1]=='1'&&ans[0]=='1'&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C' ))){
		ans+='1';
	}else{
		ans+='0';
	} 
	if (ans[1]=='1'&&ans[0]=='1'&&ans[2]=='1'&&(a==b)&&(s1[2]==s2[2]+1||s2[2]==s1[2]+1)){
		ans+='1';
	}else{
		ans+='0';
	} 
	cout<<ans;
	return 0;
} 
