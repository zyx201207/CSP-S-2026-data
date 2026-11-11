#include<bits/stdc++.h>
#define int long long
using namespace std;
string s="";
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s+='1';
	}else{
		s+='0';
	}
	if(s[0]=='1'&&s1[0]==s2[0]&&s1[1]==s2[1]){
		s+='1';
	}else{
		s+='0';
	}
	if(s[1]=='1'&&s[0]=='1'&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))==1){
		s+='1';
	}else{
		s+='0';
	}
	int a=s1[2]-'A'+1;
	int b=s2[2]-'A'+1;
	//cout<<a<<' '<<b<<'\n';
	if(s[2]=='1'&&s[1]=='1'&&s[0]=='1'&&abs(a-b)==1){
		s+='1';
	}else{
		s+='0';
	}
	cout<<s;
	return 0;
} /*
02 02B 02 01A
*/
